#include <vector>
using std::vector;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            ans += (helper(q[1]) - helper(q[0] - 1) + 1) / 2;
        }
        return ans;
    }
private:
    long long helper(long long i) {
        long long ans = 0, j = 1, k = 1;
        while (i >= j * 4) {
            ans += (j * 4 - j) * k;
            k++;
            j *= 4;
        }
        return ans + (i - j + 1) * k;
    }
};