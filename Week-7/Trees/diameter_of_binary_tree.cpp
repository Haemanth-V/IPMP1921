//Question link: https://leetcode.com/problems/diameter-of-binary-tree/


//Method 1: O(n^2)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return -1;
        return max(maxDepth(root->left)+maxDepth(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int maxDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};




//Method 2: O(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameter(root, &height);
    }
    int diameter(TreeNode *node, int *height){
        
        if(node == NULL){
            *height = 0;
            return -1;
        }
        
        int lh = 0, rh = 0;
        int ld = diameter(node->left, &lh);
        int rd = diameter(node->right, &rh);
        *height = 1 + max(lh,rh);
        return max(lh+rh, max(ld, rd));
    }
};
