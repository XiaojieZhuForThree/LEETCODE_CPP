#include <vector>
#include "ListNode.h"
#include <unordered_set>
using std::vector;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<ListNode*> v;
        std::unordered_set<int> s(begin(nums), end(nums));
        while (head) {
            if (!s.count(head->val)) v.push_back(head);
            head = head->next;
        }
        if (v.empty()) return nullptr;
        for (auto n : v) n->next = nullptr;
        for (int i = 1; i < size(v); i++) {
            v[i - 1]->next = v[i];
            v[i]->next = nullptr;
        }
        return v[0];
        
    }
};