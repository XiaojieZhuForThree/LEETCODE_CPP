#include <vector>
#include <set>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    vector<int> countMentions(int n, vector<vector<string>> &events)
    {
        vector<int> ans(n, 0);
        std::set<int> here;
        vector<vector<int>> off(n);
        for (auto &i : events)
        {
            if (i[0] == "MESSAGE")
            {
                if (i[2] == "HERE") here.insert(stoi(i[1]));
                if (i[2] == "HERE" || i[2] == "ALL")
                {
                    for (int &i : ans) i++;
                }
                else
                {
                    string t = "";
                    bool flag = false;
                    for (char c : i[2])
                    {
                        if (flag)
                        {
                            if (c == ' ')
                            {
                                flag = false;
                                ans[stoi(t)]++;
                                t = "";
                            }
                            else t += c;
                        }
                        if (c == 'd') flag = true;
                    }
                    ans[stoi(t)]++;
                }
            }
            else
            {
                off[stoi(i[2])].push_back(stoi(i[1]));
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j : off[i])
            {
                auto it = here.lower_bound(j);
                while (it != here.end())
                {
                    if (((*it) - j) < 60) ans[i]--;
                    it++;
                }
            }
        }
        return ans;
    }
};