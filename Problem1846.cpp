#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        arr[0] = 1;
        for (int i = 1; i < size(arr); i++) {
            if (arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr[size(arr) - 1];
    }
};
