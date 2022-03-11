class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        
        while(n--) {
            fast = fast->next;
        }
        
        ListNode* prev = NULL;
        while(fast&&slow) {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        
        if(slow->next && prev)
            prev->next = slow->next;
        else if(prev)
            prev->next = NULL;
        else
            head=head->next;  
        
        return head;
    }
};
