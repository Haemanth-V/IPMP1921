//Question link: https://leetcode.com/contest/biweekly-contest-53/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0, j=nums.size()-1; i<j; i++, j--)
            maxSum = max(maxSum, nums[i]+nums[j]);
        return maxSum;
    }
};
