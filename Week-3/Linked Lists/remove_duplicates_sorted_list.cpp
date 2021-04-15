//Question link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *temp = head;
        while(cur != NULL){
            temp = cur->next;
            while(temp != NULL && cur->val == temp->val){
                cur->next = temp->next;
                temp = temp->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
