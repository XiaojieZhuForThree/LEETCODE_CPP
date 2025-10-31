#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        std::unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i)) ans.push_back(i);
            s.insert(i);
        }
        return ans;
    }
};