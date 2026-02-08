#include "TreeNode.h"
#include <vector>
using std::pair;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
private:
    pair<bool, int> helper(TreeNode* node) {
        if (node == nullptr) return {true, 0};
        auto l = helper(node->left), r = helper(node->right);
        return {l.first && r.first && std::abs(l.second - r.second) <= 1, std::max(l.second, r.second) + 1};
    }
};