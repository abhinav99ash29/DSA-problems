class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *c=head,*n=head;
        while(n!=NULL && n->next!=NULL && n->next->next!=NULL) {
            c = c->next;
            n = n->next->next;
            if (c == n)  return true;
        }
        return false;
    }
};
