//Question link: https://leetcode.com/problems/minimum-path-sum/

//Recursive method:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid, int i=0, int j=0){
        if(i==grid.size()-1 && j==grid[i].size()-1)
            return grid[i][j];
        if(i>grid.size()-1 || j>grid[i].size()-1)
            return INT_MAX;
        int sum = grid[i][j] + min(minPathSum(grid,i+1,j),minPathSum(grid,i,j+1));
        //cout<<i<<", "<<j<<": "<<sum<<"\n";
        return sum;
    }
};


//DP approach:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid, int i=0, int j=0){
        int n = grid.size(), m = grid[0].size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)
                    dp[i][j] = INT_MAX;
                else if(i==1 && j==1)
                    dp[i][j] = grid[0][0];
                else 
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        
        return dp[n][m];
        
    }
};
