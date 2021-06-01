//Question link: https://leetcode.com/problems/validate-binary-search-tree/

//Method 1:
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
    bool isBST(TreeNode *root, TreeNode *l = NULL, TreeNode *r = NULL){
        if(root == NULL)
            return true;
        
        if(l && root->val <= l->val || r && root->val >= r->val)
            return false;
        
        return isBST(root->left, l, root) && isBST(root->right, root, r);
    }
};




//Method 2: Using inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        for(int i=1; i<inorder.size(); i++)
            if(inorder[i-1] >= inorder[i])
                return false;
        return true;
    }
    void inOrder(TreeNode *root, vector<int> &res){
        if(root == NULL)
            return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};
