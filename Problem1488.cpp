#include <vector>
#include <unordered_map>
#include <set>
using std::vector;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        std::unordered_map<int , int> full;
        std::set<int> dry;
        vector<int> ans(size(rains) , 1);
        for(int i = 0; i < size(rains); ++i){
            if(rains[i]) {
                int lake = rains[i];
                if(full.count(lake)) {
                    auto it = dry.lower_bound(full[lake]);
                    if (it == dry.end()) return {};
                    ans[*it] = lake;
                    dry.erase(it);
                }
                full[lake] = i;
                ans[i] = -1;
            } 
            else dry.insert(i);
        }
        return ans;
    }
};