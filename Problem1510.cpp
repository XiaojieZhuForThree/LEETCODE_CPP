#include <vector>
using std::vector;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> canWin(n + 1);
        canWin[1] = true;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                if (!canWin[i - j*j]) {
                    canWin[i] = true;
                    break;
                }
            }
        }
        return canWin[n];        
    }
};
