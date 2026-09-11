#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        unordered_set<int> s; 
        for (int i = 0; i < size(digits); i++) {
            if (digits[i] == 0) continue;
            int k = digits[i];
            digits[i] = -1;
            dfs(digits, s, k, 1);
            digits[i] = k;
        }
        return size(s);
    }
private:
    void dfs(vector<int>& A, unordered_set<int>& s, int k, int j) {
        if (j == 3) {
            if (k % 2 == 0) s.insert(k);
            return;
        }
        for (int i = 0; i < size(A); i++) {
            if (A[i] == -1) continue;
            int t = A[i];
            A[i] = -1;
            dfs(A, s, k * 10 + t, j + 1);
            A[i] = t;
        }
    }
};
