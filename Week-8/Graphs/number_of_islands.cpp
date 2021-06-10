//Question link: https://leetcode.com/problems/number-of-islands/

//Using DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        bool visited[300][300];
        memset(visited, false, sizeof(visited));
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
    
    bool isSafe(vector<vector<char> > &grid, int i, int j, bool visited[][300]){
        return i>=0 && j>=0 && i<grid.size() && j<grid[i].size() && grid[i][j] == '1' && !visited[i][j];
    }
    
    void DFS(vector<vector<char> > &grid, int i, int j, bool visited[][300]){       
        static int rows[] = {-1, 0, 0, 1};
        static int cols[] = {0, -1, 1, 0};
        visited[i][j] = true;
        for(int k=0; k<4; k++)
            if(isSafe(grid, i+rows[k], j+cols[k], visited))
                DFS(grid, i+rows[k], j+cols[k], visited);      
    }
    
};
