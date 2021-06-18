//Question link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int start=0, maxLen = 1;
        
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
    
        for(int l=3; l<=n; l++)
            for(int i=0, j=l-1; j<n; i++, j++)
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(maxLen < l){
                        maxLen = l;
                        start = i;
                    }
                }
        
        return s.substr(start, maxLen);
    }
};
