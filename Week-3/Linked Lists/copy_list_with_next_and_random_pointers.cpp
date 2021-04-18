//Question link: https://leetcode.com/problems/copy-list-with-random-pointer/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return NULL;
        
        Node *copy, *cur = head;
        
        while(cur){
            copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = cur->next? cur->next->next: NULL;
        }
        
        cur = head;
        while(cur){
            cur->next->random = cur->random? cur->random->next: NULL;
            cur = cur->next? cur->next->next: NULL;
        }
        
        Node *original = head;
        copy = head->next;
        cur = copy;
        
        while(original && copy){
            original->next = original->next? original->next->next: NULL;
            copy->next = copy->next? copy->next->next: NULL;
            original = original->next;
            copy = copy->next;
        }
        
        return cur;
    }
};
