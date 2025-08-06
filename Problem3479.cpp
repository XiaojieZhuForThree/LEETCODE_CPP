#include <vector>
using std::vector;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = size(baskets);
        vector<int> bit(n * 4, -1);
        build(bit, baskets, 0, 0, n - 1);
        int ans = 0;
        for (int i : fruits) {
            if (!query(bit, 0, 0, n - 1, i)) ans++;
        }
        return ans;
    }
private:
    void build(vector<int>& bit, vector<int>& baskets, int i, int l, int r) {
        if (l == r) {
            bit[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(bit, baskets, i * 2 + 1, l, mid);
        build(bit, baskets, i * 2 + 2, mid + 1, r);
        bit[i] = std::max(bit[i * 2 + 1], bit[i * 2 + 2]);
    }
    bool query(vector<int>& bit,int i, int l, int r, int k) {
        if (bit[i] < k) return false;
        if (l == r) {
            bit[i] = -1;
            return true;
        }
        int m = l + (r - l) / 2;
        if (bit[i * 2 + 1] >= k) {
            query(bit, i * 2 + 1, l, m, k);
            bit[i] = std::max(bit[i * 2 + 1], bit[i * 2 + 2]);
        } else {
            query(bit, i * 2 + 2, m + 1, r, k);
            bit[i] = std::max(bit[i * 2 + 1], bit[i * 2 + 2]);
        }
        return true;
    }
};