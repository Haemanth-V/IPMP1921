//Question link: https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2)
                break;
            if(ptr1 == NULL)
                ptr1 = headB;
            if(ptr2 == NULL)
                ptr2 = headA;
        }
        return ptr1;
    }
};
