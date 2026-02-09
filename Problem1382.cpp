#include "TreeNode.h"
#include <vector>
using std::vector;

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v = helper1(root);
        return helper2(v, 0, size(v) - 1);
    }
private:
    vector<TreeNode*> helper1(TreeNode* node) {
        if (node == nullptr) return {};
        auto ans = helper1(node->left);
        ans.push_back(node);
        for (TreeNode* n : helper1(node->right)) ans.push_back(n);
        return ans;
    }
    TreeNode* helper2(vector<TreeNode*>& v, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) {
            TreeNode* n = v[l];
            n->left = nullptr;
            n->right = nullptr;
            return n;
        }
        int m = l + (r - l) / 2;
        TreeNode* h = v[m];
        h->left = helper2(v, l, m - 1);
        h->right = helper2(v, m + 1, r);
        return h;
    }
};