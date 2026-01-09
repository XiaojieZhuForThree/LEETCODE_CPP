#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root);
    }
private:
    TreeNode* helper(TreeNode* node) {
        int l = dep(node->left), r = dep(node->right);
        if (l == r) return node;
        if (l > r) return helper(node->left);
        return helper(node->right);
    }
    int dep(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(dep(node->left), dep(node->right));
    }
};