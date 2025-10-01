class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, e = numBottles;
        while (e >= numExchange) {
            ans += e / numExchange;
            e = e % numExchange + e / numExchange;
        }
        return ans;
    }
};