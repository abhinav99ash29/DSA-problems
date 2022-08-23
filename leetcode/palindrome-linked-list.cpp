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
        ListNode* prev = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        int n = 0;
        while(node) {
            n++;
            node = node->next;
        }
        ListNode* prev = nullptr;
        node = head;
        for(int i=1;i<=n/2;i++) {
            prev = node;
            node = node->next;
        }
        if (prev) prev->next = nullptr;
        node = rev(node);
        ListNode* node1 = head;
        while(node && node1) {
            if (node->val != node1->val) return false;
            node = node->next;
            node1 = node1->next;
        }
        return true;
       
    }
};
