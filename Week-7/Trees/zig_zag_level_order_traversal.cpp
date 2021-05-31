//Question link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        int i=0; 
        int size = 1;
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            vector<int> t = levelOrder(q, size);
            if(i&1)
                reverse(t.begin(), t.end());
            res.push_back(t);
            i++;
        }
        return res;
    }
    vector<int> levelOrder(queue<TreeNode *> &q, int size){
        vector<int> res;
        for(int i=0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            res.push_back(node->val);
        }
        return res;
    }
};
