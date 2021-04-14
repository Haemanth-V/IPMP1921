//Question link: https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = head;
        int i;
        for(i=1; cur->next != NULL && i<=k; i++, cur = cur->next);
        if(i<k)
            return head;
        i = 1;
        cur = head;
        while(cur != NULL && i<=k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            i++;
        }
        if(next != NULL)
            head->next = reverseKGroup(next, k);
        return prev;
    }
};
