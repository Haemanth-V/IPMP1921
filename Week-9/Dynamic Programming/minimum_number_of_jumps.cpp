//Question link: https://leetcode.com/problems/jump-game-ii/

//Recursive approach:
class Solution {
public:
    int jump(vector<int>& nums, int i=0) {
        
        if(i == nums.size()-1)
            return 0;
        
        int minJumps = INT_MAX;
        
        for(int j=1; j<=nums[i] && i+j < nums.size(); j++)
            minJumps = min(minJumps, jump(nums,i+j));
        
        return minJumps == INT_MAX? INT_MAX: minJumps+1;
    }
};


//DP Approach:
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            dp[i] = INT_MAX;
            for(int j=0; j<i; j++)
                if(i-j <= nums[j])
                dp[i] = min(dp[i], dp[j]+1);
        }
        
        return dp[n-1];
    }
};
