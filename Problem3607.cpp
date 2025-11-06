#include <unordered_map>
#include <vector>
#include <set>
using std::vector;
struct UF {
    std::unordered_map<int, int> p;
    UF(int c) {
        for (int i = 1; i <= c; i++) p[i] = i;
    }
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        p[pj] = pi;
    }
    int find(int i) {
        if (p[i] != i) p[i] = find(p[i]);
        return p[i];
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UF uf(c);
        for (auto& p : connections) uf.merge(p[0], p[1]);
        std::unordered_map<int, std::set<int>> m;
        for (int i = 1; i <= c; i++) m[uf.find(i)].insert(i);
        vector<int> ans;
        for (auto& p : queries) {
            if (p[0] == 2) m[uf.find(p[1])].erase(p[1]);
            else if (m[uf.find(p[1])].count(p[1])) ans.push_back(p[1]);
            else if (m[uf.find(p[1])].empty()) ans.push_back(-1);
            else ans.push_back(*begin(m[uf.find(p[1])]));
        }
        return ans;
    }
};