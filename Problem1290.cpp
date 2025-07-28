#include "ListNode.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = head->val + (ans << 1);
            head = head->next;
        }
        return ans;
    }
};