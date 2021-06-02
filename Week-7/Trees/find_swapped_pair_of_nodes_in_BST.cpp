//Qyestion link: https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    void swap(TreeNode *a, TreeNode *b){
        int t = a->val;
        a->val = b->val;
        b->val = t;
    }
    void recoverTree(TreeNode *root){
        TreeNode *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
        recoverTree(root, first, middle, last, prev);
        //cout<<first<<" "<<middle<<" "<<last;
        if(last)
            swap(first, last);
        else 
            swap(first, middle);
    }
    void recoverTree(TreeNode* root, TreeNode *&first, TreeNode *&middle, TreeNode *&last, TreeNode *&prev) {
        if(root == NULL)
            return;
        recoverTree(root->left, first, middle, last, prev);
        if(prev && root->val < prev->val){
            if(first){
                last = root;
                return;
            }
            first = prev;
            middle = root;
        }
        prev = root;
        recoverTree(root->right, first, middle, last, prev);
    }
};
