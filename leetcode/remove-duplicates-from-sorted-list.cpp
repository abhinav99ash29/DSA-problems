/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head, int prev = -101) {
        if (!head) return NULL;
        if (head->val == prev) {
            return deleteDuplicates(head->next, prev);
        }
        head->next = deleteDuplicates(head->next, head->val);
        return head;
    }
};
