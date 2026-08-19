#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
public:
    unordered_map<int, vector<int>> m;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        for (auto& r : reservedSeats) {
            if (!m.count(r[0])) m[r[0]] = vector<int>(11, 0);
            m[r[0]][r[1]] = 1;
        }
        ans += 2 * (n - size(m));
        for (auto& p : m) {
            int i = p.first;
            bool a = check(i, 2), b = check(i, 4), c = check(i, 6);
            if (a && c) ans += 2;
            else if (a || b || c) ans++;
        }
        return ans;
    }
private:
    bool check(int i, int j) {
        for (int k = 0; k < 4; k++) {
            if (m[i][j + k] == 1) return false;
        }
        return true;
    }
};