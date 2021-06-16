//Question link: https://leetcode.com/problems/partition-equal-subset-sum/

//Recursive approach:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        return equalSubsets(nums, sum/2, 0);
    }
    bool equalSubsets(vector<int> &nums, int sum, int i){
        if(i >= nums.size() || sum < 0)
            return false;
        if(sum == 0)
            return true;
        return equalSubsets(nums, sum-nums[i], i+1) || equalSubsets(nums, sum, i+1);
    }
};

//DP approach:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        
        sum /= 2;
        int dp[n+1][sum+1];
        
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(nums[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        
        return dp[n][sum] == sum;
    }
};
