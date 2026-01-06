#include "TreeNode.h"
#include <deque>
#include <climits>

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0, cur = 0, sum = INT_MIN;
        std::deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            cur++;
            int s = 0;
            for (int i = size(q); i > 0; i--) {
                TreeNode* n = q.front();
                q.pop_front();
                s += n->val;
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            if (s > sum) {
                sum = s;
                ans = cur;
            }
        }
        return ans;
    }
};