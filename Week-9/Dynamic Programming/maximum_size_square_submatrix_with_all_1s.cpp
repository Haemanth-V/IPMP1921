//Question link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int S[m][n];
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0 || j==0)
                    S[i][j] = matrix[i][j]-'0';
                else if(matrix[i][j] == '0')
                    S[i][j] = 0;
                else
                    S[i][j] = min(S[i-1][j-1], min(S[i-1][j], S[i][j-1]))+1;
        
        int maxSide = INT_MIN;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                maxSide = max(maxSide, S[i][j]);
        
        return maxSide*maxSide;
    }
};
