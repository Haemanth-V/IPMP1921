//Question link: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(), *prev;
        prev = head;
        while(l1 != NULL || l2 != NULL){
            int num = carry;
            if(l1 != NULL){
                num += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                num += l2->val;
                l2 = l2->next;
            }
            prev->next = new ListNode(num%10);
            prev = prev->next;
            carry = num/10;
        }
        if(carry != 0)
            prev->next = new ListNode(carry);
        return head->next;
    }
};
