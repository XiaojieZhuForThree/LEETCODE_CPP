#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), comp);
        return arr;
    }
private:
    static bool comp(int a, int b) {
        if (help(a) == help(b)) return a < b;
        return help(a) < help(b);
    }
    static int help(int i) {
        int ans = 0;
        while (i) {
            ans += (i & 1);
            i >>= 1;
        }
        return ans;
    }
};