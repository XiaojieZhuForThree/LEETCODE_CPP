#include "TreeNode.h"
#include <algorithm>
class Solution {
public:
    long long ans = 0, mod = 1000000007;
    int maxProduct(TreeNode* root) {
        process(root);
        helper(root, root->val);
        return ans % mod;
    }
private:
    void process(TreeNode* node) {
        if (node == nullptr) return;
        process(node->left);
        process(node->right);
        if (node->left) node->val += node->left->val;
        if (node->right) node->val += node->right->val;

    } 
    void helper(TreeNode* node, int s) {
        if (node == nullptr) return;
        helper(node->left, s);
        helper(node->right, s);
        long long cur = (long long)(node->val) * (s - node->val);
        ans = std::max(ans, cur);
    } 
};