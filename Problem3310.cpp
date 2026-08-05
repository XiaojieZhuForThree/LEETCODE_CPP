#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::vector;
using std::unordered_map;
using std::unordered_set;


struct UF {
    vector<int> p;
    UF(int n) {
        p.resize(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int par(int i) {
        if (p[i] != i) p[i] = par(p[i]);
        return p[i];
    }
    void merge(int i, int j) {
        int pi = par(i), pj = par(j);
        p[pj] = pi; 
    } 
};
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> m;
        UF uf(n);
        vector<int> tot, ans;
        for (int i = 0; i < n; i++) tot.push_back(i);
        for (auto& i : invocations) {
            m[i[0]].push_back(i[1]);
            uf.merge(i[0], i[1]);
        }
        unordered_set<int> g;
        getGroup(m, g, k);
        for (int i = 0; i < n; i++) {
            if (g.count(i)) continue;
            if (uf.par(i) == uf.par(k)) return tot;
            ans.push_back(i);
        }
        return ans;
    }
private:
    void getGroup(unordered_map<int, vector<int>>& m, unordered_set<int>& g, int k) {
        if (g.count(k)) return;
        g.insert(k);
        for (int j : m[k]) getGroup(m, g, j);
    }
};
