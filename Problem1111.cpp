#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution { 
public: 
    vector<int> maxDepthAfterSplit(string seq) { 
        vector<int> ans(size(seq));
        int d = 0;
        for (int i = 0; i < size(seq); i++) {
            if (seq[i] == '(') {
                d++;
                ans[i] = d % 2;
            } else {
                ans[i] = d % 2;
                d--;
            }
        }
        return ans;
    } 
};
