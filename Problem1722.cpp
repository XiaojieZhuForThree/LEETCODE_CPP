#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = size(source);
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < size(allowedSwaps) ; i++){
            adj[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            adj[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        vector<int> vis(n , 0);
        vector<int> group(n);
        for(int i = 0 ; i < n ; i++){
            group[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, group , i);
            }
        }
        
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i < n ; i++){
            mp[group[i]].push_back(i);
        }
        
        int ans = 0;
        for(auto i : mp){
            vector<int> pos = i.second;
            unordered_map<int, int> check;
            for(int j = 0 ; j < pos.size() ; j++){
                check[source[pos[j]]]++;
            }
            
            for(int j = 0 ; j < pos.size() ; j++){
                if(check[target[pos[j]]] > 0){
                    check[target[pos[j]]]--;
                }else{
                    ans++;
                }
            }
            
        }
        return ans;
    }
private:
    void dfs(int pos, vector<vector<int>>& adj, vector<int>& vis, vector<int>& group, int top){
        group[pos] = top;
        vis[pos] = 1;
        for(int i = 0 ; i < adj[pos].size() ; i++){
            int cur = adj[pos][i];
            if(vis[cur] == 0){
                dfs(cur, adj, vis, group, top);
            }
        }
    }
};