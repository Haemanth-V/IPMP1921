//Question link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


//Method 1: O(n^2)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder){
        TreeNode *root = NULL;
        for(int i=0; i<preorder.size(); i++)
            root = bstFromPreorder(root, preorder[i]);
        return root;
    }
    TreeNode* bstFromPreorder(TreeNode *root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        if(root->val > val)    
            root->left = bstFromPreorder(root->left, val);
        else
            root->right = bstFromPreorder(root->right, val);
        return root;
    }
};




//Method 2: O(n)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorder(preorder, i, INT_MIN, INT_MAX);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder, int &index, int min, int max) {
       if(index >= preorder.size()) 
           return NULL;
        if(preorder[index] <= min || preorder[index] >= max)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[index]);
        index++;
        root->left = bstFromPreorder(preorder, index, min, root->val);
        root->right = bstFromPreorder(preorder, index, root->val, max);
        return root;
    }
};
