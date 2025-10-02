class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles, e = numBottles, x = numExchange;
        while (e >= x) {
            ans++;
            e -= x - 1;
            x++;
        }
        return ans;
    }
};