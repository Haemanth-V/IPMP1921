//Question link:

//Recursive
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return longestPalindromeSubseq(s,0,s.length()-1);
    }
    
    int longestPalindromeSubseq(string s, int i, int j) {
        if(i == j)
            return 1;
        if(i > j)
            return 0;
        if(s[i] == s[j])
            return 2+longestPalindromeSubseq(s,i+1,j-1);
        return max(longestPalindromeSubseq(s,i+1,j),longestPalindromeSubseq(s,i,j-1));
    }
};



//DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        
        for(int l=2; l<=n; l++)
            for(int i=0, j=l-1; j<n; i++,j++)
                if(s[i] == s[j]){
                    if(l == 2)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 2+dp[i+1][j-1];
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        
        return dp[0][n-1];
    }
};
