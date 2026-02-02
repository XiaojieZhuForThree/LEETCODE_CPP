#include <vector>
#include <set>
using std::vector;
using std::pair;
using std::set;
using std::min;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = 1e18;
        long long cur = 0;
        k--;
        set<pair<int, int>> actual, not_used;
        for(int l = 1, r = 1; r < nums.size(); r++) {
            while(r - l > dist) {
                if(actual.count({nums[l], l})) {
                    cur -= nums[l];
                    actual.erase({nums[l], l});
                }

                if (not_used.count({nums[l], l})) not_used.erase({nums[l], l});
                l++;
            }

            not_used.insert({nums[r], r});

            while(actual.size() < k && not_used.size()) {
                actual.insert(*not_used.begin());
                cur += not_used.begin()->first;
                not_used.erase(not_used.begin());
            }
            
            while(not_used.size() && actual.rbegin()->first > not_used.begin()->first) {
                not_used.insert(*actual.rbegin());
                cur -= actual.rbegin()->first;
                actual.erase(*actual.rbegin());
                
                actual.insert(*not_used.begin());
                cur += not_used.begin()->first;

                not_used.erase(*not_used.begin());
            }
            if (actual.size() == k) ans = min(ans, cur);
        }
        return ans + nums[0];
    }
};