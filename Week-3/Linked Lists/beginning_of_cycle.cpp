//Question link: https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        
        int len = 1;
        while(fast->next != slow){
            fast = fast->next;
            len++;
        }
        
        slow = head;
        fast = head;
        for(int i=0; i<len; i++)
            fast = fast->next;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
