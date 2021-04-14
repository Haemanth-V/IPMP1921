//Question link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *main = head;
        for(int i=1; i<=n; i++)
            temp = temp->next;
        if(temp == NULL){
            return main->next;
        }
        while(temp->next != NULL){
            main = main->next;
            temp = temp->next;
        }
        main->next = main->next->next;
        return head;
    }
};
