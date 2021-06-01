//Question link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if(l > r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, r);
        return root;
    }
};
