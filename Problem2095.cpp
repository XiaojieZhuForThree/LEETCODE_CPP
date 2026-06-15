#include "ListNode.h"
#include <vector>
using std::vector;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        vector<ListNode*> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        if (size(v) == 1) return nullptr;
        ListNode* node = new ListNode(0), *itr = node;
        for (int i = 0; i < size(v); i++) {
            if (i == size(v) / 2) continue;
            itr->next = v[i];
            itr = itr->next;
        }
        itr->next = nullptr;
        return node->next;
    }
};
