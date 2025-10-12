#include <vector>
#include <unordered_map>
using std::vector;

typedef long long ll;
class Solution {
public:
    vector<ll> factor;
    vector<ll> invfactor;
    vector<int> nums;
    int n;
    const ll mod = (1e9 + 7);
    vector<vector<vector<std::unordered_map<int, ll>>>> dp;
    ll pow(ll a, ll b) {
        ll base = a, cur = 0, l = 1, ans = 1;
        while ((l << cur) <= b) {
            if (((l << cur) & b) != 0) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            cur++;
        }
        return ans;
    }
    
    ll inv(ll a) { return pow(a, mod - 2); }

    int count(int m)
    {
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            int b = 1 << i;
            if ((b & m) ==b) cnt++;
        }
        return cnt;
    }

    ll dfs(int mask, int m, int k, int i)
    {
        if (k < 0) return 0;
        if (m == 0)
        {
            int c = count(mask);
            if (c == k) return 1;
            return 0; 
        }
        if (i == n) return 0;
        
        if (dp[m][k][i].count(mask)) return dp[m][k][i][mask];
        ll cur = 0;
        cur = dfs((mask >> 1), m, k - (mask & 1), i + 1);
        cur = cur % mod;

        ll v = 1;
        for (int c = 1; c <= m; c++)
        {
            v = v * (ll)nums[i] % mod;
            int m1 = mask + c;
            int k1 = k - (1 & m1);
            ll a = factor[m] * invfactor[m - c] % mod  * invfactor[c] % mod * dfs(m1 >> 1, m - c, k1, i + 1) % mod * v;
            cur =( cur + a ) % mod;
        }

        dp[m][k][i][mask]  = cur;
        return cur;
    }
    int magicalSum(int M, int K, vector<int>& nums1) {
        factor = vector<ll>(M + 1, 1);
        invfactor = vector<ll>(M + 1, 1);
        nums = nums1;
        for (int i = 2; i <= M; i++) factor[i] = (i * factor[i - 1]) % mod;
        for (int i = 2; i <= M; i++) invfactor[i] = inv(factor[i]);
        n = nums.size();
        dp = vector<vector<vector<std::unordered_map<int, ll>>>>(M + 1, vector<vector<std::unordered_map<int, ll>>>(K + 1, vector<std::unordered_map<int, ll>>(n)));
        return dfs(0, M, K, 0);

    }
};