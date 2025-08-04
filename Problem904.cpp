#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, i = 0, cur = 0;
        std::unordered_map<int, int> m;
        for (int j = 0; j < size(fruits); j++) {
            cur++;
            m[fruits[j]]++;
            while (size(m) > 2) {
                m[fruits[i]]--;
                if (m[fruits[i]] == 0) m.erase(fruits[i]);
                cur--;
                i++;
            }
            ans = std::max(ans, cur);
        }
        return ans;
    }
};