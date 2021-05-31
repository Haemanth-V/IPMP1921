//Question link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution {
public:
    TreeNode* bstToGst(TreeNode *root){
        int add = 0;
        gst(root, &add);
        return root;
    }
    void gst(TreeNode* root, int *add) {
        if(root == NULL)
            return;
        gst(root->right, add);
        *add += root->val;
        root->val = *add;
        gst(root->left, add);
    }
};
