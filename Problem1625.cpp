#include <string>
#include <deque>
#include <unordered_set>
using std::string;

class Solution {
public:
    string findLexSmallestString(string str, int a, int b) {
        std::deque<string> q;
        std::unordered_set<string> s;
        q.push_front(str);    
        int n = size(str);
        string ans = str;
        while (!q.empty()) {
            string cur = q.front();
            q.pop_front();
            if (s.count(cur)) continue;
            ans = min(ans, cur);
            s.insert(cur);
            string nxt = cur;
            for(int i=1; i<n; i+=2) nxt[i]= '0' + (nxt[i] - '0' + a) % 10;
            q.push_front(nxt);
            q.push_front(cur.substr(n-b,b)+cur.substr(0,n-b));
        }
        return ans;
    }
};