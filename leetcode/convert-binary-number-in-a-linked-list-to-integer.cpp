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
    
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        int res=0;
        int pw=0;
        head = rev(head);
        while(head) {
            res+=pow(2,pw)*head->val;
            pw++;
            head = head->next;
        }
        return res;
    }
};
