//Question link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int nodes = 0;
        ListNode *temp = head;
        while(temp != NULL){
            nodes++;
            temp = temp->next;
        }
        
        if(nodes < k || 2*k - 1 == nodes)
            return head;
        
        ListNode *x_prev = NULL, *x = head, *y_prev = NULL, *y = head;
        for(int i=1; i<k; i++){
            x_prev = x;
            x = x->next;
        }
        
        for(int i=1; i<=nodes-k; i++){
            y_prev = y;
            y = y->next;
        }
        
        if(x_prev)
            x_prev->next = y;
        
        if(y_prev)
            y_prev->next = x;
        
        temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        if(k==1)
            head = y;
        if(k==nodes)
            head = x;
        
        return head;
    }
};
