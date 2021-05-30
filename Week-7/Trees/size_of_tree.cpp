//Question link: 

//Method 1: Normal recursion visiting all nodes - O(n)
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};





//Method 2
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int hl = 0, hr = 0;
        TreeNode *l = root, *r = root;
        while(l){
            hl++;
            l=l->left;
        }
        while(r){
            hr++;
            r=r->right;
        }
        if(hl == hr)
            return pow(2,hl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


