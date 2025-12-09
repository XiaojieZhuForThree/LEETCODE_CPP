#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        std::unordered_map<int, long long> cnt, pr;
        long long ans = 0;
        for (int i : nums) {
            if (i % 2 == 0) ans += pr[i / 2];
            pr[i] += cnt[i * 2];
            cnt[i]++;
        }
        return ans % 1000000007;
    }
};