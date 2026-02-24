#include "TreeNode.h"

class Solution {
public:
    int ans = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) ans += node->val;
        if (node->left) node->left->val += node->val * 2;
        if (node->right) node->right->val += node->val * 2;
        dfs(node->left);
        dfs(node->right); 
    }
};