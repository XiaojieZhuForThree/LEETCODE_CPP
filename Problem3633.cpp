#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < size(landStartTime); i++) {
            for (int j = 0; j < size(waterStartTime); j++) {
                ans = min(ans, max(landStartTime[i], waterStartTime[j] + waterDuration[j]) + landDuration[i]);
                ans = min(ans, max(waterStartTime[j], landStartTime[i] + landDuration[i]) + waterDuration[j]);
            }
        }
        return ans;
    }
};
