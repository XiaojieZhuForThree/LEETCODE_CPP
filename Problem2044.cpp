#include <vector>
using std::vector;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int t = 0;
        for (int i : nums) t |= i;
        return dfs(nums, 0, 0, t);
    }
private:
    int dfs(vector<int>& A, int i, int c, int t) {
        if (i == size(A)) return c == t;
        return dfs(A, i + 1, c, t) + dfs(A, i + 1, c | A[i], t);
    }
};