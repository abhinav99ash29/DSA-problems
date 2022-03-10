class Solution {
public:
    
    ListNode* reverse(ListNode* head, ListNode* prev = nullptr) {
        if (head == nullptr) return prev;
        ListNode* temp = head->next;
        head->next = prev;
        return reverse(temp, head);
    }
    
    void reorderList(ListNode* head) {
        if (head != nullptr) {
            head->next = reverse(head->next);
            reorderList(head->next);
        }
    }
};
