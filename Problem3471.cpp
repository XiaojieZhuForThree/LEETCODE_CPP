#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int v[51];
        for (int i = 0; i + k <= size(nums); i++) {
            unordered_set<int> s;
            for (int j = i; j < i + k; j++) s.insert(nums[j]);
            for (int t : s) v[t]++;
        }
        for (int i = 50; i >= 0; i--) {
            if (v[i] == 1) return i;
        }
        return -1;
    }
};
