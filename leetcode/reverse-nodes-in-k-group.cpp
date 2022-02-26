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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k==1) return head;
        
        ListNode* node = head;
        
        int i=1;
        
        while(node->next!=NULL && i<k) {
            i++;
            node=node->next;
        }
        
        if (i<k) return head;
        
        i=1;
        
        ListNode* prev = NULL;
        
        node = head;
        
        while(i<=k && node!=NULL) {
            
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
            i++;
            
        }
        
        head->next = reverseKGroup(node, k);
        
        return prev;
        
    }
};
