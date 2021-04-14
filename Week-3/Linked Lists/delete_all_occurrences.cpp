//Question link:

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL, *cur = head;
        while(cur != NULL){
            if(cur->val == val){
                if(prev == NULL)
                    head = cur->next;
                else
                    prev->next = cur->next;
            }
            else
                prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

//Bit more optimised
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        while(head != NULL && head->val == val)
            head = head->next;
        cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};
