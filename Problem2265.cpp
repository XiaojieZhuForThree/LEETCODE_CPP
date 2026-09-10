#include "TreeNode.h"
#include <utility>
using std::pair;

class Solution {
public:
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        if (node->left == nullptr && node->right == nullptr) {
            ans++;
            return {node->val, 1};
        }
        auto l = dfs(node->left), r = dfs(node->right);
        if ((node->val + l.first + r.first) / (l.second + r.second + 1) == node->val) ans++;
        return {node->val + l.first + r.first, l.second + r.second + 1};
    }
};