//Question link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildTree(preorder, inorder, 0, inorder.size(), index);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int &preIndex) {
        if(preIndex >= preorder.size() || inStart > inEnd)
            return NULL;
        int lEnd = find(inorder.begin()+inStart, inorder.begin() + inEnd, preorder[preIndex]) - inorder.begin();
        TreeNode *root = new TreeNode(preorder[preIndex]);
        preIndex++;
        root->left = buildTree(preorder, inorder, inStart, lEnd-1, preIndex);
        root->right = buildTree(preorder, inorder, lEnd+1, inEnd, preIndex);
        return root;
    }
};
