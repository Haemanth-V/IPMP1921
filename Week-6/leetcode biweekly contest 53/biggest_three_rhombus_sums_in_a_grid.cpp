//Question link: https://leetcode.com/contest/biweekly-contest-53/problems/get-biggest-three-rhombus-sums-in-a-grid/

//Error for large grids
class Solution {
public:
    int area(vector<vector<int> > grid, int r, int c, int side){
        int k;
        int sum = grid[r][c];
        for(k=1; k<=side; k++)
            sum += grid[r+k][c-k] + grid[r+k][c+k];
        r += 2*side;
        for(k=0; k<side; k++)
            if(k == 0)
                sum += grid[r][c];
            else
                sum += grid[r-k][c-k] + grid[r-k][c+k];
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int, greater<int> > s;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                int side = min(min(j, (int)grid[i].size()-j-1), ((int)grid.size()-i-1)/2);
                int sum = 0;
                for(int k=0; k<=side; k++)
                    sum = max(sum, area(grid, i, j, k));
                s.insert(sum);
            }
        }
        vector<int> res;
        int c = 1;
        for(auto it = s.begin(); it != s.end() && c <= 3; it++, c++)
            res.push_back(*it);
        
        return res;
    }
};
