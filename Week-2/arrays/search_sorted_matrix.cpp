//Question link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0, m = matrix.size(), n = matrix[0].size(); 
        while(r<m && matrix[r][n-1] < target)
            r++;
        if(r == m)
            return false;
        int l=0, u=n-1;
        while(l<=u){
            int mid = l+(u-l)/2;
            if(matrix[r][mid] == target)
                return true;
            if(matrix[r][mid] > target)
                u = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};
