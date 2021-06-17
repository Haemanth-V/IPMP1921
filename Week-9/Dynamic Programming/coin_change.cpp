//Question link: 

//Recursive 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return change(amount, coins, 0);
        
    }
    int change(int amount, vector<int>& coins, int i) {
        if(amount == 0)
            return 1;
        
        if(amount < 0 || i >= coins.size())
            return 0;
        
        return change(amount-coins[i], coins, i) + change(amount, coins, i+1);
    }
};


//DP - Bottom up
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n][amount+1];
        
        for(int i=0; i<n; i++)
            dp[i][0] = 1;
        
        for(int i=0; i<n; i++)
            for(int j=1; j<=amount; j++){
                dp[i][j] = 0;
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
                if(coins[i] <= j)
                    dp[i][j] += dp[i][j-coins[i]];
            }
        
        return dp[n-1][amount];
    }
};


//DP - Top down
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        fill_n(dp, amount+1, 0);
        
        dp[0] = 1;
        
        for(int i=0; i<coins.size(); i++)
            for(int j=coins[i]; j<=amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        
        return dp[amount];
    }
};
