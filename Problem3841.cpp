#include <vector>
#include <utility>
#include <string>
using std::vector;
using std::pair;
using std::string;
using std::swap;


struct FenwickXor {
    int n;
    vector<int> bit;
    FenwickXor(int n=0){ init(n); }
    
    void init(int _n){ 
        n = _n; 
        bit.assign(n + 1, 0); 
    }
    void add(int i, int val){
        for(; i <= n; i += i & -i) bit[i] ^= val;
    }
    void range_xor(int l, int r, int val){
        if(l > r) return;
        add(l, val);
        if(r + 1 <= n) add(r + 1, val);
    }
    int point(int i){
        int res = 0;
        for(; i > 0; i -= i & -i) res ^= bit[i];
        return res;
    }
};

class Solution {
public:
    int LOG = 20;
    vector<vector<int>> up;
    vector<int> depth, tin, tout;
    int timer = 0;
    vector<int> base_pref;
    vector<int> cur_mask;
    FenwickXor bit;
    vector<vector<int>> adj;

    void dfs_prep(int v, int p){
        tin[v] = ++timer;
        up[0][v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        
        base_pref[v] = (p == -1) ? cur_mask[v] : base_pref[p] ^ cur_mask[v];

        for(int to : adj[v]){
            if(to != p) dfs_prep(to, v);
        }
        tout[v] = timer;
    }

    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for(int k = 0; diff; ++k){
            if(diff & 1) a = up[k][a];
            diff >>= 1;
        }
        if(a == b) return a;
        for(int k = LOG - 1; k >= 0; --k){
            if(up[k][a] != -1 && up[k][a] != up[k][b]){
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    pair<int,int> get_digits(const string &q){
        int a = 0, b = 0, i = 0;
        while(i < (int)q.size() && !isdigit(q[i])) ++i;
        while(i < (int)q.size() && isdigit(q[i])) { a = a * 10 + (q[i] - '0'); ++i; }
        while(i < (int)q.size() && !isdigit(q[i])) ++i;
        while(i < (int)q.size() && isdigit(q[i])) { b = b * 10 + (q[i] - '0'); ++i; }
        return {a, b};
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        cur_mask.assign(n, 0);
        for(int i = 0; i < n; ++i) cur_mask[i] = 1 << (s[i] - 'a');

        tin.assign(n, 0); tout.assign(n, 0);
        base_pref.assign(n, 0); depth.assign(n, 0);

        LOG = log2(n) + 1;
        up.assign(LOG, vector<int>(n, -1));

        timer = 0;
        dfs_prep(0, -1);
        for(int k = 1; k < LOG; ++k){
            for(int v = 0; v < n; ++v){
                int mid = up[k-1][v];
                up[k][v] = (mid == -1 ? -1 : up[k-1][mid]);
            }
        }

        bit.init(n);
        vector<bool> ans;

        for(const string &Q : queries){
            if(Q.empty()) continue;
            
            if(Q[0] == 'q'){ 
                auto [u, v] = get_digits(Q);
                
                int pref_u = base_pref[u] ^ bit.point(tin[u]);
                int pref_v = base_pref[v] ^ bit.point(tin[v]);
                int w = lca(u, v);
                
                int path_xor = pref_u ^ pref_v ^ (cur_mask[w]);
                bool can_be_palindrome = (path_xor == 0) || ((path_xor & (path_xor - 1)) == 0);
                ans.push_back(can_be_palindrome);
            } else { 
                auto [u, _ignore] = get_digits(Q);
                char newc = Q.back();
                int newmask = 1 << (newc - 'a');
                int delta = cur_mask[u] ^ newmask;
                if(delta != 0){
                    bit.range_xor(tin[u], tout[u], delta);
                    cur_mask[u] = newmask;
                }
            }
        }
        return ans;
    }
};
