#include <vector>
using std::vector;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for (int i = 0; i < size(colors) - 1; i++) {
            for (int j = i + 1; j < size(colors); j++) {
                if (colors[i] == colors[j]) continue;
                ans = std::max(ans, j - i);
            }
        }
        return ans;
    }
};
