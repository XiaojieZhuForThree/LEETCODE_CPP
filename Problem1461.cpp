#include <string>
#include <unordered_set>
#include <cmath>
using std::string;
using std::unordered_set;


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for (int i = 0; i + k <= size(s); i++) st.insert(s.substr(i, k));
        return st.size() == pow(2, k);
    }
};