//Question link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        Node *t = head->next;
        head->next = flatten(head->child);
        if(head->next != NULL)
            head->next->prev = head;
        head->child = NULL;
        Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        
        t = flatten(t);
        temp->next = t;
        if(t != NULL)
            t->prev = temp;
        return head;
    }
};
