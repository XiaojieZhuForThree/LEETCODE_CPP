#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string, string> m;
        for (auto& v : knowledge) m[v[0]] = v[1];
        for (int i = 0; i < size(s);) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') j++;
                string key = s.substr(i + 1, j - i - 1);
                if (!m.count(key)) ans += '?';
                else ans += m[key];
                i = j + 1;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
