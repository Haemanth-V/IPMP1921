//Question link: https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res = {};
        binaryTreePaths(root, res);
        return res;
    }
    void binaryTreePaths(TreeNode* root, vector<string> &res, string path = ""){
        if(root == NULL)
            return;
        path.append(to_string(root->val));
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
            return;
        }
        else
            path.append("->");
        binaryTreePaths(root->left, res, path);
        binaryTreePaths(root->right, res, path);
    }
};
