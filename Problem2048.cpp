#include <vector>
#include <algorithm>

class Solution {
public:
    int nextBeautifulNumber(int n) {
        std::vector<int> v, cnt(8, 0);
        helper(0, cnt, v);
        sort(begin(v), end(v));
        for (int i : v) {
            if (i > n) return i;
        }
        return -1;
    }
private:
    void helper(int i, std::vector<int>& cnt, std::vector<int>& v) {
        if (i > 0 && yes(cnt)) v.push_back(i);
        if (i > 1224444) return;
        for (int j = 1; j <= 7; j++) {
            if (cnt[j] < j) {
                cnt[j]++;
                helper(i * 10 + j, cnt, v);
                cnt[j]--;
            }
        }
    }
    bool yes(std::vector<int>& cnt) {
        for (int i = 1; i <= 7; i++) {
            if (cnt[i] != 0 && cnt[i] != i) return false;
        }
        return true;
    }
};