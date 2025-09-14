#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::unordered_map<string, int> m1, m2;
        std::unordered_set<string> s;
        vector<string> ans;
        for (int i = 0; i < size(wordlist); i++) {
            s.insert(wordlist[i]);
            string pw1 = helper1(wordlist[i]);
            string pw2 = helper2(wordlist[i]);
            if (m1.count(pw1)) continue;
            else m1[pw1] = i;
            if (m2.count(pw2)) continue;
            else m2[pw2] = i;
        }
        for (const auto &q : queries) {
            if (s.count(q)) ans.push_back(q);
            else {
                string pq1 = helper1(q), pq2 = helper2(q);
                if (m1.count(pq1)) ans.push_back(wordlist[m1[pq1]]);
                else if (m2.count(pq2)) ans.push_back(wordlist[m2[pq2]]);
                else ans.push_back("");
            }
        }
        return ans;
    }
private:
    string helper1(const string& s) {
        string ans;
        for (char c : s) ans += tolower(c);
        return ans;
    }
    string helper2(const string& s) {
        string ans;
        for (char c : s) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ans += '#';
            else ans += c;
        }
        return ans;
    }
};