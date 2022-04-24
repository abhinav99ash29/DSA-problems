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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<lists.size();i++) {
            ListNode* temp = lists[i];
            while(temp != NULL) {
                q.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(!q.empty()) {
            int x = q.top(); q.pop();
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        ans = ans->next;
        return ans;
    }
};
