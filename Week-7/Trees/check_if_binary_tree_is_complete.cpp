//Question link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

//Method 1: Iterative - Use level order traversal
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        bool nonFull = false;
        q.push(root);
        while(!q.empty()){
            TreeNode *u = q.front();
            q.pop();
            if(u->left){
                if(nonFull)
                    return false;
                q.push(u->left);
            }
            else
                nonFull = true;
            if(u->right){
                if(nonFull)
                    return false;
                q.push(u->right);
            }
            else
                nonFull = true;
        }
        return true;
    }
};




//Method 2: Recursive - array index based logic
class Solution {
    int nodes = 0;
public:
    bool isCompleteTree(TreeNode* root) {
        nodes = countNodes(root);
        return isComplete(root, 0);
    }
    bool isComplete(TreeNode *root, long i){
        if(root == NULL)
            return true;
        if(i >= nodes)
            return false;
        return isComplete(root->left, 2*i+1) && isComplete(root->right, 2*i+2);
    }
    int countNodes(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
