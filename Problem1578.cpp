#include <string>
#include <vector>
#include <numeric>
using std::string;
using std::vector;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0, k = 0, a = std::accumulate(begin(neededTime), end(neededTime), 0);
        while (i < size(colors)) {
            int t = neededTime[i];
            while (j < size(colors) && colors[j] == colors[i]) {
                t = std::max(t, neededTime[j]);
                j++;
            }
            k += t;
            i = j;
        }
        return a - k;
    }
};