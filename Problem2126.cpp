#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        long long cur = mass;
        for (int i : asteroids) {
            if (cur < i) return false;
            cur += i; 
        }
        return true;
    }
};
