#include "ListNode.h"
#include <vector>
using std::vector;

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int ans = 0, l = 0, r = size(v) - 1;
        while (l < r) ans = std::max(ans, v[l++] + v[r--]);
        return ans;
    }
};
