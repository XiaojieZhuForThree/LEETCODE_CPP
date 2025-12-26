#include <string>
using std::string;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = size(customers), cn = 0, cur = 0, ans = n;
        for (char c : customers) {
            if (c == 'N') {
                cn++;
                cur++;
            }
        }
        int ry = 0, rn = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') ry++;
            else rn++;
            int cand = cn + ry - rn;
            if (cand <= cur) {
                ans = i;
                cur = cand;
            }
        }
        return ans;
    }
};