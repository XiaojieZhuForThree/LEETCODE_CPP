#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto comp = [](vector<int>& a, vector<int> b) {
            if (a[0] * a[0] + a[1] * a[1] == b[0] * b[0] + b[1] * b[1]) return a[0] * a[1] > b[0] * b[1];
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        };
        std::sort(dimensions.begin(), dimensions.end(), comp);
        return dimensions[0][0] * dimensions[0][1];
    }
};