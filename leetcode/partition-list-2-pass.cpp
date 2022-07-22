class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *sol, *node, *node1;
        sol = new ListNode();
        
        node = head;
        node1 = sol;
        while(node) {
            if (node->val < x) {
                node1->next = new ListNode(node->val);
                node1 = node1->next;
            }
            node = node->next;
        }
        node = head;
        while(node) {
            if (node->val >= x) {
                node1->next = new ListNode(node->val);
                node1 = node1->next;
            }
            node = node->next;
        }
        
        return sol->next;
    }
};
