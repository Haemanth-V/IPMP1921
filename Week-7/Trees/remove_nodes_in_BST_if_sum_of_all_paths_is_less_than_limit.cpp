//Question link: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL)
            return NULL;
        if(!root->left && !root->right){
            if(root->val < limit)
                return NULL;
            return root;
        }
        root->left = sufficientSubset(root->left, limit-root->val);
        root->right = sufficientSubset(root->right, limit-root->val);
        if(!root->left && !root->right)
            return NULL;
        return root;
    }
};
