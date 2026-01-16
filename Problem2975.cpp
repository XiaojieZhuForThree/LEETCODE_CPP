#include <vector>
#include <map>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.push_back(m);
        hFences.insert(hFences.begin(), 1);
        vFences.push_back(n);
        vFences.insert(vFences.begin(), 1);

        int ans = -1;
        std::map<int, int> cnt;
        int len = hFences.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) cnt[hFences[j] - hFences[i]] = 1;
        }
        len = vFences.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (cnt.count(vFences[j] - vFences[i])) ans = std::max(ans, vFences[j] - vFences[i]);
            }
        }
        if(ans == -1) return ans;
        const int mod = 1e9 + 7;
        return 1LL * ans * ans % mod;
    }
};