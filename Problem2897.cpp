#include <vector>
using std::vector;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(31);
        for (int i = 0;i < size(nums); i++) {
            int j = 30;
            while (nums[i] > 0) {
                if(nums[i] % 2) bit[j]++;
                nums[i] /= 2;
                j--;
            }
        }
        int mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0;i < k;i++) {
            long long num = 0;
            for (int j = 0;j < 31;j++) {
                num *= 2;
                if (bit[j]) {
                    num += 1;
                    bit[j]--;
                }
            }
            sum = (sum + (num * num) % mod) % mod;
        }
        return sum;
    }
};
