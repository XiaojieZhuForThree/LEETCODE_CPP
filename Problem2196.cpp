#include "TreeNode.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::vector;
using std::unordered_map;
using std::unordered_set;


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> s;
        for (auto& d : descriptions) {
            int h = d[0], c = d[1], dir = d[2];
            s.insert(c);
            if (!m.count(h)) m[h] = new TreeNode(h);
            if (!m.count(c)) m[c] = new TreeNode(c);
            if (dir == 1) m[h]->left = m[c];
            else m[h]->right = m[c];
        }
        for (auto& p : m) {
            if (s.count(p.first)) continue;
            return p.second;
        }
        return nullptr;
    }
};
