#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& q : queries) {
            if (yes(q, dictionary)) ans.push_back(q);
        }
        return ans;
    }
private:
    bool yes(string& q, vector<string>& d) {
        for (auto& r : d) {
            if (dist(q, r) <= 2) return true;
        }
        return false;
    }
    int dist(string& a, string& b) {
        int ans = 0;
        for (int i = 0; i < size(a); i++) {
            if (a[i] != b[i]) ans++;
        }
        return ans;
    }
};