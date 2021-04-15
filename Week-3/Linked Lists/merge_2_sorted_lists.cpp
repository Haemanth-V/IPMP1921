//Question link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *prev, *head1 = l1, *head2 = l2;
        prev = dummy;
        while(head1 != NULL || head2 != NULL){
            if(head2 == NULL || (head1 != NULL && head1->val <= head2->val)){
                prev->next = head1;
                prev = head1;
                head1 = head1->next; 
            }
            else{
                prev->next = head2;
                prev = head2;
                head2 = head2->next;
            }
        }
        return dummy->next;
    }
};
