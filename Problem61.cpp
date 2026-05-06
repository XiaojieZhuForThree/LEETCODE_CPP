#include "ListNode.h"
#include <vector>
using std::vector;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        vector<ListNode*> v, w;
        ListNode* d = head;
        while (d) {
            v.push_back(d);
            d = d->next;
        }
        int n = size(v);
        k %= n;
        if (k == 0) return head;
        for (int i = n - k; i < n; i++) w.push_back(v[i]);
        for (int i = 0; i < n - k; i++) w.push_back(v[i]);
        for (int i = 0; i < n - 1; i++) {
            w[i]->next = w[i + 1];
            w[i + 1]->next = nullptr;
        }
        return w[0];
    }
};