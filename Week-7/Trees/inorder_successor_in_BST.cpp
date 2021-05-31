//Question link: interviewbit.com/problems/next-greater-number-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   //Find node B
   TreeNode *B_node = A;
   while(B_node->val != B){
       if(B < B_node->val)
           B_node = B_node->left;
       else 
           B_node = B_node->right;
   }
   
   if(B_node->right){
       B_node = B_node->right;
       while(B_node->left)
           B_node = B_node->left;
       return B_node;
   }
   
   B_node = NULL;
   while(A->val != B){
       if(B < A->val){
           B_node = A;
           A = A->left;
       }
       else
           A = A->right;
   }
   return B_node;
    
}
