//Question link: https://leetcode.com/problems/maximum-subarray/

//Divide and conquer approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArraySum(nums, 0, nums.size()-1);
    }
    int maxSubArraySum(vector<int> nums, int l, int r){
        if(l == r)
            return nums[l];
        int m = (l+r)/2;
        return max(max(maxSubArraySum(nums,l,m), maxSubArraySum(nums,m+1,r)), maxSum(nums,l,m,r));
    }
    int maxSum(vector<int> nums, int l, int m, int r){
        int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
        for(int i=m; i>=l; i--){
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        sum = 0;
        for(int i=m+1; i<=r; i++){
            sum+=nums[i];
            rightSum = max(rightSum, sum);
        }
        
        return max(leftSum + rightSum, max(leftSum, rightSum));
    }
};




//Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};
