#include <unordered_set>
#include <string>
#include <algorithm>
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::unordered_set<std::string> s = helper1();
        return helper2(n, s);
    }
private:
    std::unordered_set<std::string> helper1() {
        std::unordered_set<std::string> ans;
        for (long long i = 1; i <= 1000000000; i *= 2) {
            std::string ds = "";
            long long j = i;
            while (j > 0) {
                ds += std::to_string(j % 10);
                j /= 10;
            }
            std::sort(ds.begin(), ds.end());
            ans.insert(ds);
        }
        return ans;
    }
    bool helper2(int i, std::unordered_set<std::string>& s) {
        std::string ds = "";
        while (i > 0) {
            ds += std::to_string(i % 10);
            i /= 10;
        }
        std::sort(ds.begin(), ds.end());
        return s.count(ds);
    }
};