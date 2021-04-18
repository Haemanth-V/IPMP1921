//Question link: https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode* mergeSorted(ListNode *head1, ListNode *head2){
        if(head2 == NULL)
            return head1;
        if(head1 == NULL)
            return head2;
        
        ListNode *head = NULL;
        if(head1->val <= head2->val){
            head = head1;
            head->next = mergeSorted(head1->next, head2);
        }
        
        else{
            head = head2;
            head->next = mergeSorted(head1, head2->next);
        }
        
        return head;
    }
    
    ListNode* sortList(ListNode* &head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        //Split list
        ListNode *a = head, *b = head, *fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            b = b->next;
            fast = fast->next->next;
        }
        
        ListNode *t = b;
        b = b->next;
        t->next = NULL;  //split
        
        sortList(a);
        sortList(b);
        head = mergeSorted(a,b);
        return head;
    }
};
