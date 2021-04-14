//Question link: https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *tail = head, *temp = head, *new_tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        k = k%len;
        for(int i=1; i<=k; i++)
            temp = temp->next;
        while(temp != NULL && temp->next != NULL){
            new_tail = new_tail->next;
            temp = temp->next;
        }
        tail->next = head;
        head = new_tail->next;
        new_tail -> next = NULL;
        return head;
    }
};
