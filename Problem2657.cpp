#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = size(A);
        vector<int> ans(n, 0);
        unordered_set<int> used;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = n - size(used);
            used.insert(A[i]);
            used.insert(B[i]);
        }
        return ans;
    }
};
