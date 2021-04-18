//Question link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *temp = head;
        while(cur != NULL){
            temp = cur->next;
            bool duplicate = false;
            while(temp != NULL && cur->val == temp->val){
                cur->next = temp->next;
                duplicate = true;
                temp = temp->next;
            }
            if(duplicate){
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
