class Solution {
public:
    bool canAliceWin(int n) {
        int t = 10;
        bool a = true;
        while (n) {
            if (n < t) return !a;
            else {
                n -= t;
                t--;
                a = !a;
            }
        }
        return !a;
    }
};
