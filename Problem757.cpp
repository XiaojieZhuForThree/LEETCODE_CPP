#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        std::sort(begin(intervals), end(intervals), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int p1 = -1, p2 = -1;
        int ans = 0;

        for (auto &it : intervals) {
            int s = it[0], e = it[1];

            if (p2 < s) {              
                ans += 2;
                p1 = e - 1;
                p2 = e;
            }
            else if (p1 < s) {         
                ans += 1;
                p1 = p2;
                p2 = e;
            }
        }
        return ans;
    }
};