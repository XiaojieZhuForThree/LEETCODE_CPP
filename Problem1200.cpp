#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> ans;
        int d = helper(arr);
        for (int i = 0; i + 1 < size(arr); i++) {
            if (arr[i + 1] - arr[i] == d) ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
private:
    int helper(vector<int>& arr) {
        int ans = arr[1] - arr[0];
        for (int i = 2; i < size(arr); i++) ans = std::min(ans, arr[i] - arr[i - 1]);
        return ans;
    }
};