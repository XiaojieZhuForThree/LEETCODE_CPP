#include <vector>
using std::vector;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (yes(nums)) return 0;
        int i = get(nums);
        vector<int> nxt;
        for (int j = 0; j < size(nums); j++) {
            if (j == i) {
                nxt.push_back(nums[j] + nums[j + 1]);
                j++;
            } else nxt.push_back(nums[j]);
        }
        return 1 + minimumPairRemoval(nxt);
    }
private:
    bool yes(vector<int>& v) {
        for (int i = 1; i < size(v); i++) {
            if (v[i] < v[i - 1]) return false;
        }
        return true;
    }
    int get(vector<int>& v) {
        int s = v[0] + v[1], i = 0;
        for (int j = 1; j + 1 < size(v); j++) {
            if (v[j] + v[j + 1] < s) {
                s = v[j] + v[j + 1];
                i = j;
            }
        }
        return i;
    }
};