#include <vector>
#include <algorithm>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rep;
        for (int i : arr) rep.push_back(i);
        sort(begin(rep), end(rep));
        int cnt = 1;
        unordered_map<int, int> m;
        for (int i : rep) {
            if (m.count(i)) continue;
            m[i] = cnt++;
        }
        vector<int> ans;
        for (int i : arr) ans.push_back(m[i]);
        return ans;
    }
};
