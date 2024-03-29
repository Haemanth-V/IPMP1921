//Question link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        int dp[n1+1][n2+1];
        int len = 0;
        
        for(int i=0; i<=n1; i++)
            for(int j=0; j<=n2; j++)
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    len = max(len, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
        
        return len;
    }
};
