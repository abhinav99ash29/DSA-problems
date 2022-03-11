class Solution {
public:
    
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        if (list1 && list2) {
            if (list1->val > list2->val) {
                list2->next = mergeTwo(list1, list2->next);
                return list2;
            } else {
                list1->next = mergeTwo(list1->next, list2);
                return list1;
            }
        }
        if (list1) return list1;
        
        return list2;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int len = lists.size();
        
        while(len>1) {
            for(int i=0;i<len/2;i++) {
                lists[i] = mergeTwo(lists[i],lists[len-i-1]);
            }
            len = (len+1)/2;
        }
        
        return lists.front();
    }
};
