//Question link: https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode *> q;
        vector<vector<int> > res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> t = levelOrderTraversal(q, size);
            if(t.size() != 0)
               res.push_back(t);
        }
        return res;
    }
    vector<int> levelOrderTraversal(queue<TreeNode *> &q, int size){
        if(q.empty())
            return {};
        vector<int> res;
        for(int i=0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return res;
    }
};
