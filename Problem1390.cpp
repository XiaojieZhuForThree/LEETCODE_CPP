#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<int> pms = sieve(50000);
        unordered_map<int, int> meet = helper(pms);
        int ans = 0;
        for (int i : nums) {
            if (!meet.count(i)) continue;
            ans += meet[i] + 1 + i;
        }
        return ans;
    }
private:
    vector<int> sieve(int n) {
        vector<bool> v(n + 1, true);
        vector<int> ans;
        for (int i = 2; i <= n; i++) {
            if (!v[i]) continue;
            for (int j = 2 * i; j <= n; j += i) v[j] = false;
        }
        for (int i = 2; i <= n; i++) {
            if (v[i]) ans.push_back(i);
        }
        return ans;
    }
    unordered_map<int, int> helper(vector<int>& pms) {
        unordered_map<int, int> ans;
        for (int i = 0; i < size(pms); i++) {
            if ((long long)(pms[i]) * pms[i] * pms[i] <= 100000) ans[pms[i] * pms[i] * pms[i]] = pms[i] + pms[i] * pms[i];
            for (int j = i + 1; j < size(pms) && (long long)(pms[i]) * pms[j] <= 100000; j++) ans[pms[i] * pms[j]] = pms[i] + pms[j];
        }
        return ans;
    }
};