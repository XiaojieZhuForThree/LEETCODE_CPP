#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < size(nums); i++) {
            unordered_map<int, int> o, e;
            for (int j = i; j < size(nums); j++) {
                if (nums[j] % 2) o[nums[j]]++;
                else e[nums[j]]++;
                if (size(e) == size(o)) ans = std::max(ans, j - i + 1);
            }
        }
        return ans;
    }
};