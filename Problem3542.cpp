#include <deque>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        std::deque<int> q;
        q.push_back(0);

        for (int i = 0; i < size(nums); i++) {
            while (!q.empty() && q.back() > nums[i]) q.pop_back();
            if (q.empty() || q.back() < nums[i]) {
                ans++;
                q.push_back(nums[i]);
            }
        }
        return ans;
    }
};