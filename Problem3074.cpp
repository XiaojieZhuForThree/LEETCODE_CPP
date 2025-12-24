#include <vector>
#include <numeric>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot = std::accumulate(begin(apple), end(apple), 0);
        sort(begin(capacity), end(capacity), std::greater<int>());
        for (int i = 0; i < size(capacity); i++) {
            tot -= capacity[i];
            if (tot <= 0) return i + 1;
        }
        return -1;
    }
};