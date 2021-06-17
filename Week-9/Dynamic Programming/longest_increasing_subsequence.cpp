//Question link: https://leetcode.com/problems/longest-increasing-subsequence/

//Recursive
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int el = INT_MIN, int i=0) {
        if(i >= nums.size())
            return 0;
        if(nums[i] <= el)
            return lengthOfLIS(nums, el, i+1);
        return max(1+lengthOfLIS(nums, nums[i], i+1), lengthOfLIS(nums, el, i+1));
    }
};





//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int el = INT_MIN, int i=0) {
        int n = nums.size();
        int dp[n];
        fill_n(dp, n, 1);
        
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
                
        return *max_element(dp, dp+n);
    }
};
