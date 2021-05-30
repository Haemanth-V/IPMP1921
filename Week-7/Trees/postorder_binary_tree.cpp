//Question link: https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    void postorder(TreeNode *root, vector<int> &res){
        if(root == NULL)
            return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};
