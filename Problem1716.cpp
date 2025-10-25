class Solution {
public:
    int totalMoney(int n) {
        int add = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i % 7 == 0) add++;
            ans += add + (i % 7);
        }
        return ans;
    }
};