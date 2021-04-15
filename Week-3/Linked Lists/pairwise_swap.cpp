//Question link: https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *node1 = head, *node2 = NULL;
        ListNode *prev = NULL;
        while(node1 != NULL && node1->next != NULL){
            if(node2 == NULL)
                head = node1->next;
            node2 = node1->next;
            node1->next = node2->next;
            if(prev != NULL)
                prev->next = node2;
            prev = node1;
            node2->next = node1;
            node1 = node1->next;
        }
        return head;
    }
};
