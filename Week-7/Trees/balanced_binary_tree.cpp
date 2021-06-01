//Question link: https://leetcode.com/problems/balanced-binary-tree/

//Method 1: Brute force - O(n^2)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh > rh+1 || lh < rh-1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1+max(height(root->left), height(root->right));
    }
};




//Method 2: optimised - O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }
    bool isBalanced(TreeNode *root, int &height){
        if(root == NULL){
            height = 0;
            return true;
        }
        int lh = 0, rh = 0;
        bool left, right;
        left = isBalanced(root->left, lh);
        right = isBalanced(root->right, rh);
        height = max(lh, rh) + 1;
        if(abs(lh - rh) > 1)
            return false;
        return left && right;
    }
};
