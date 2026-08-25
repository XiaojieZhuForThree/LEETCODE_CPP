#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        for (int i = 1; k * i <= 200; i++) {
            if (!s.count(i * k)) return i * k;
        }
        return -1;
    }
};
