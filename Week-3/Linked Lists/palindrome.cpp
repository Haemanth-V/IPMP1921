//Question link:

//Method 1: Using stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *temp = head;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            int t = s.top();
            if(t!=temp->val)
                return false;
            s.pop();
            temp = temp->next;
        }
        return true;
    }
};

//Method 2: Using recursion 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return palindrome_check(head, head);
    }
    bool palindrome_check(ListNode *&left, ListNode *right){
        if(right == NULL)
            return true;
        bool res = palindrome_check(left, right->next);
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }
};
 
