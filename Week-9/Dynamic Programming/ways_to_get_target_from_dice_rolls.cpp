//Question link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

//Recursive
class Solution {
public:
    long mod = 10e9+7;
    int numRollsToTarget(int d, int f, int target) {
        if(d == 0)
            return target == 0;
        int ways = 0;
        for(int i=1; i<=f; i++)
            ways = (ways+numRollsToTarget(d-1,f,target-i))%mod;
        return ways;
    }
};




//DP - O(d*f*target)
class Solution {
public:
    long mod = 1000000007;
    int numRollsToTarget(int d, int f, int target) {
        //cout<<(mod);
        int dp[d+1][target+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=target && i<=f; i++)
            dp[1][i] = 1;
        
        for(int i=1; i<=d; i++)
            for(int j=1; j<=target; j++){
                for(int k=1; k<=f && k<j; k++)
                    dp[i][j] = ((long)dp[i][j]+dp[i-1][j-k])%mod;
                //dp[i][j] = (dp[i][j]+mod)%mod;
            }
        
        return dp[d][target];
    }
};
