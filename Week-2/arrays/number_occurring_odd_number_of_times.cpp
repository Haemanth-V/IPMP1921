//Question link: https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int odd_count = 0;
        for(int i=0; i<nums.size(); i++)
            odd_count = odd_count^nums[i];
        return odd_count;
    }
};
