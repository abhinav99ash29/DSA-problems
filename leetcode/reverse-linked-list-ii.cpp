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
    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        while(head!=NULL) {
            ListNode* temp = head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        ListNode *leftN=NULL, *rightN=NULL, *prev=NULL, *next=NULL;
        int cnt=1;
        
        while(node->next!=NULL) {
            if (cnt==left) break;
            prev=node;
            node=node->next;
            cnt++;
        }
        leftN = node;
        
        while(node->next!=NULL) {
            if (cnt==right) break;
            node=node->next;
            cnt++;
        }
        rightN=node;
        
        next=node->next;
        rightN->next=NULL;
        
        ListNode* reversed = reverse(leftN);
        ListNode* reversed1 = reversed;
        if (prev)
            prev->next=reversed;
        
        while(reversed->next!=NULL)
            reversed=reversed->next;
        
        reversed->next=next;
        return left==1 ? reversed1 : head;
    }
};
