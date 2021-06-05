//Question link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *x = head;
        while(x != NULL){
            n++;
            x = x->next;
        }
        return sortedListToBST(head, n);
    }
    TreeNode* sortedListToBST(ListNode* &head, int n) {
        while(n == 0)
            return NULL;
        TreeNode *left = sortedListToBST(head, n/2);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        TreeNode *right = sortedListToBST(head, n-n/2-1);
        root->right = right;
        return root;
    }
};
