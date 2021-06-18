//Question link: https://leetcode.com/problems/palindrome-partitioning-ii/

//Recursive
class Solution {
public:
    int minCut(string s) {
        return minCut(s, 0, s.length()-1);
    }
    int minCut(string s, int i, int j) {
        if(i == j || isPalindrome(s,i,j))
            return 0;
        int minCuts = INT_MAX;
        for(int k=i; k<j; k++){
            int cuts = minCut(s, i, k) + minCut(s, k+1, j) + 1;
            minCuts = min(minCuts, cuts);
        }
        return minCuts;
    }
    bool isPalindrome(string s, int i, int j){
        string t = s.substr(i,j-i+1);
        string revt = t;
        reverse(revt.begin(), revt.end());
        return (t == revt);
    }
};




//DP - O(N^3)
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        int dp[n][n];
        bool pal[n][n];
        memset(pal, false, sizeof(pal));
        
        for(int i=0; i<n; i++){
            dp[i][i] = 0;
            pal[i][i] = true;
        }
        
        for(int l=2; l<=n; l++)
            for(int i=0, j=l-1; j<n; i++,j++){
                if(l == 2)
                    pal[i][j] = (s[i] == s[j]);
                else
                    pal[i][j] = (s[i] == s[j]) && pal[i+1][j-1];
                    
                if(pal[i][j])
                    dp[i][j] = 0;
                    
                else{
                    dp[i][j] = INT_MAX;
                    for(int k=i; k<j; k++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                }
            }
        
        return dp[0][n-1];
    }
};




//DP - O(n^2)
