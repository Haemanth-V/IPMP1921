//Question link: https://leetcode.com/problems/super-egg-drop/

//Recursive
class Solution {
public:
    int superEggDrop(int k, int n) {
        if(n==1 || n==0)
            return n;
        
        if(k==1)
            return n;
        
        int minMoves = INT_MAX, res;
        
        for(int i=1; i<=n; i++){
            res = max(superEggDrop(k-1,i-1), superEggDrop(k,n-i));
            minMoves = min(minMoves, res);
        }
        
        return minMoves+1;
    }
};




//DP
class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[k+1][n+1];

    for(int i=0; i<=k; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int i=0; i<=n; i++)
        dp[1][i] = i;

    for(int i=2; i<=k; i++)
        for(int j=2; j<=n; j++){
            dp[i][j] = INT_MAX;
            for(int k=1; k<=j; k++){
                int ans = 1+max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(dp[i][j], ans);
            }
        }

    return dp[k][n];
    }
};
