#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        std::unordered_set<int> s, tot;
        for (int i : arr) {
            std::unordered_set<int> n;
            n.insert(i);
            for (int j : s) {
                n.insert(i | j);
            }
            for (int j : n) tot.insert(j);
            s = n;
        }
        return size(tot);
    }
};