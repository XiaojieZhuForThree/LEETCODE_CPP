#include <vector>
#include <string>
using std::vector;
using std::string;
using std::to_string;

struct Trie {
    Trie* nxt[10];
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for (int i : arr1) process(i, &t);
        int ans = 0;
        for (int i : arr2) ans = std::max(ans, helper(i, &t));
        return ans;
    }
private:
    void process(int i, Trie* t) {
        string s = to_string(i);
        for (char c : s) {
            if (t->nxt[c - '0'] == nullptr) t->nxt[c - '0'] = new Trie();
            t = t->nxt[c - '0'];
        }
    }
    int helper(int i, Trie* t) {
        string s = to_string(i);
        int ans = 0;
        for (char c : s) {
            if (t->nxt[c - '0'] == nullptr) return ans;
            ans++;
            t = t->nxt[c - '0'];
        }
        return ans;
    }
};