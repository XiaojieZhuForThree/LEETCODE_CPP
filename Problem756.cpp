#include <string>
#include <vector>
#include <unordered_set>
using std::string;
using std::vector;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        std::unordered_set<string> invalid;
        vector<vector<char>> edges(49);
        for (string& s: allowed) {
            int key = (s[0]-'A')*7+s[1]-'A';
            edges[key].push_back(s[2]);
        }
        return helper(invalid, bottom, edges);
    }
private:
    bool helper(std::unordered_set<string>& invalid, string& bottom, vector<vector<char>>& edges) {
        if (bottom.size() <= 1) return true;
        if (invalid.count(bottom)) return false;
        int n = bottom.size();
        for (int i = 0; i < n-1; i++) {
            int key = (bottom[i]-'A')*7+bottom[i+1]-'A';
            if (edges[key].empty()) {
                invalid.insert(bottom);
                return false;
            }
        }
        string path(n-1, 'A');
        if (dfs(invalid, bottom, edges, path, 0)) return true;
        invalid.insert(bottom);
        return false;
    }
    bool dfs(std::unordered_set<string>& invalid, string& s, vector<vector<char>>& edges, string& path, int idx) {
        if (idx+1 == s.size()) return helper(invalid, path, edges);
        int key = (s[idx]-'A')*7+s[idx+1]-'A'; 
        for (char c: edges[key]) {
            path[idx] = c;
            if (dfs(invalid, s, edges, path, idx+1)) return true;
        }
        return false;
    }
};