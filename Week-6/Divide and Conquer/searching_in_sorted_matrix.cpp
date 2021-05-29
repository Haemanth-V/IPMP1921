//Question link: https://leetcode.com/problems/search-a-2d-matrix-ii/

//Check - Time limit exceeded but took less than 800 ms to run
//Divide and conquer approach - O(n^1.58)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
    }
    bool search(vector<vector<int>> mat, int r1, int c1, int r2, int c2, int k){
        
        //1*2 matrix - special case
        if(r1 == r2 && c1+1 == c2 )
            return mat[r1][c1] == k || mat[r2][c2] == k;
        
        int i = (r1+r2)/2;
        int j = (c1+c2)/2;
        if(mat[i][j] == k)
            return true;
        bool res = false;
        if(i != r2 || j != c1)
            res = search(mat, r1, j, i, c2, k); //upper right 
        if(!res && mat[i][j] < k && i+1 <= r2)
            res = search(mat, i+1, c1, r2, c2, k); //lower sub-matrix
        else if(!res && j-1 >= c1)
            res = search(mat, r1, c1, r2, j-1, k); //left sub-matrix
        return res;
    }
};
