/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    ListNode* fn(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return headA;
        ListNode *tempa = headA, *tempb = headB;
        while(tempa) {
            tempb = headB;
            while(tempb) {
                if (tempb == tempa)
                    return tempa;
                tempb = tempb->next;
            }
            tempa = tempa->next;
        }
        return nullptr;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return fn(headA, headB);
    }
};
