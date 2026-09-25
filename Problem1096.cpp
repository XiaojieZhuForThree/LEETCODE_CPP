#include <string>
#include <set>
#include <vector>
using std::string;
using std::set;
using std::vector;

class Solution {
public:
    string s;
    int i = 0;
    set<string> parseExpression() {
        set<string> result;
        result.insert("");
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> current = parseTerm();

            set<string> temp;

            for (const string& a : result) {
                for (const string& b : current) temp.insert(a + b);
            }

            result = temp;
        }

        return result;
    }

    set<string> parseTerm() {
        set<string> result;

        if (s[i] == '{') {
            i++;
            set<string> part = parseExpression();
            for (const string& word : part) result.insert(word);

            while (i < s.size() && s[i] == ',') {
                i++;

                set<string> next = parseExpression();

                for (const string& word : next) {
                    result.insert(word);
                }
            }
            i++;
        } else {
            result.insert(string(1, s[i]));
            i++;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};
