//Question link: https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenStart = new ListNode(), *evenEnd;
        ListNode *oddStart = new ListNode(), *oddEnd;
        evenEnd = evenStart;
        oddEnd = oddStart;
        ListNode *temp = head;
        int i=1;
        while(temp != NULL){
            if(i%2 == 0){
               evenEnd->next = temp;
               evenEnd = temp;
            }
            else{
                oddEnd->next = temp;
                oddEnd = temp;
            }
            temp = temp->next;
            i++;
        }
        evenEnd->next = NULL;
        oddEnd->next = evenStart->next;
        return oddStart->next;
    }
};
