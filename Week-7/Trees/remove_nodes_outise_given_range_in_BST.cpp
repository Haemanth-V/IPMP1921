//Question link: https://leetcode.com/problems/trim-a-binary-search-tree/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return NULL;
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if(root->val > high)
            root = root->left;
        else if(root->val < low)
            root = root->right;
        return root;
    }
};
