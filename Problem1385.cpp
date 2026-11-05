#include <vector>
using std::vector;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int i : arr1) ans += yes(i, arr2, d);
        return ans;
    }
private:
    bool yes(int i, vector<int>& v, int d) {
        for (int j : v) {
            if (abs(i - j) <= d) return false;
        }
        return true;
    }
};
