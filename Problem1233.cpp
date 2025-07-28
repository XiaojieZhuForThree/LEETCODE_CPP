#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;

struct Trie {
    string cur;
    bool isEnd;
    std::unordered_map<string, Trie*> nxt;
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie tr;
        for (string& s : folder) process(&tr, s);
        vector<string> ans;
        for (string& s : folder) {
            if (isSub(&tr, s)) continue;
            ans.push_back(s); 
        }
        return ans;
    }
private:
    void process(Trie* tr, string& s) {
        int i = 1, j = 1;
        for (; j <= size(s); j++) {
            if (j == size(s) || s[j] == '/') {
                string cur = s.substr(i, j - i);
                if (!tr->nxt.count(cur)) tr->nxt[cur] = new Trie();
                tr = tr->nxt[cur];
                i = j + 1;
            }
        }
        tr->isEnd = true;
    }

    bool isSub(Trie* tr, string& s) {
        int i = 1, j = 1;
        for (; j <= size(s); j++) {
            if (j == size(s) || s[j] == '/') {
                string cur = s.substr(i, j - i);
                tr = tr->nxt[cur];
                if (tr->isEnd && j < size(s)) return true;
                i = j + 1;
            }
        }
        return false;
    }
};