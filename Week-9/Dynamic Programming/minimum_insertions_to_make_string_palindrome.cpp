//Question link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//Recursive
class Solution {
public:
    int minInsertions(string s) {
        return minInsertions(s,0,s.length()-1);
    }
    int minInsertions(string s, int i, int j) {
        if(i >= j)
            return 0;
        if(s[i] == s[j])
            return minInsertions(s, i+1, j-1);
        return 1+min(minInsertions(s,i+1,j),minInsertions(s,i,j-1));
    }
};



//DP
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int l=1; l<n; l++)
            for(int i=0, j=l; j<n; i++,j++)
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 1+min(dp[i+1][j], dp[i][j-1]);
        
        return dp[0][n-1];
    }
};
