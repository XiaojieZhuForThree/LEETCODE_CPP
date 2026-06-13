#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& w : words) {
            int s = helper(w, weights), m = s % 26, t = 25 - m;
            ans += 'a' + t;
        }
        return ans;
    }
private:
    int helper(string& w, vector<int>& v) {
        int ans = 0;
        for (char c : w) ans += v[c - 'a'];
        return ans;
    }
};
