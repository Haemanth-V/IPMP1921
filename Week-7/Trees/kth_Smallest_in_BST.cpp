//Question link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *res = kthLeast(root, k);
        return res->val;
        
   }
    TreeNode* kthLeast(TreeNode* root, int &k) {
        if(root == NULL)
            return NULL;
        TreeNode *left = kthLeast(root->left, k);
        if(left != NULL)
            return left;
        k--;
        if(k == 0)
            return root;
        return kthLeast(root->right, k);
    }
};
