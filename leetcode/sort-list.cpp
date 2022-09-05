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
    
    vector<ListNode*> getHalf(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while(slow && fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return {head, slow};
    }
    
    ListNode* merge(ListNode* p1, ListNode* p2) {
        ListNode* result = new ListNode();
        ListNode* node = result;
        while(p1 && p2) {
            if (p1->val < p2->val) {
                node->next = p1;
                p1 = p1->next;
            } else {
                node->next = p2;
                p2 = p2->next;
            }
            node = node->next;
        }
        while(p1) {
            node->next = p1;
            p1 = p1->next;
            node = node->next;
        }
        while(p2) {
            node->next = p2;
            p2 = p2->next;
            node = node->next;
        }
        return result->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        vector<ListNode*> p = getHalf(head);
        p[0] = sortList(p[0]);
        p[1] = sortList(p[1]);
        return merge(p[0],p[1]);
    }
};
