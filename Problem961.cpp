#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
};