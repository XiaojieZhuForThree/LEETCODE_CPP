#include <vector>
using std::vector;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(size(nums), 0), bits(32, 0);
        int j = size(nums) - 1;
        for(int i = size(nums) - 1; i >= 0; i--) {
            add(bits, nums[i]);
            while (j > i && yes(bits, nums[j])) {
                reduce(bits, nums[j]);
                j--;
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
private:
    void add(vector<int>& bits, int num) {
        for (int i = 0; i < 31; i++) {
            if (((1 << i) & num)) bits[i]++;
        }
    }
    bool yes(vector<int>& bits, int num) {
        for (int i = 0; i < 31; i++) {
            if (((1 << i) & num) && bits[i] == 1) return false;
        }
        return true;
    }
    void reduce(vector<int>& bits, int num) {
        for (int i = 0; i < 31; i++) {
            if (((1 << i) & num)) bits[i]--;
        }
    }
};