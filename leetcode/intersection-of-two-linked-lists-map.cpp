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
        map<ListNode*, bool> mp;
        if (!headA || !headB) return headA;
        ListNode* temp = headA;
        while(temp) {
            mp[temp] = true;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp) {
            if (mp[temp])
                return temp;
            temp = temp->next;
        }
        
        return nullptr;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return fn(headA, headB);
    }
};
