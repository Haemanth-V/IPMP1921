//Question link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return findTarget(root, k, s);
    }
     bool findTarget(TreeNode* root, int k, unordered_set<int> &s) {
        if(root == NULL)
            return false;
         bool res = findTarget(root->left, k, s);
         if(res)
             return res;
         if(s.find(k - root->val) != s.end())
             return true;
         s.insert(root->val);
         return findTarget(root->right, k, s);
    }
};
