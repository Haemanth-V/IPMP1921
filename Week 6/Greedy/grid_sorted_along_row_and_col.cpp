//Question link: https://www.hackerrank.com/challenges/grid-challenge/problem

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    for(int i=0; i<grid.size(); i++)
        sort(grid[i].begin(), grid[i].end());
    for(int i=0; i<grid[0].length(); i++){
        for(int j=0; j<grid.size()-1; j++)
            if(grid[j][i] > grid[j+1][i])
                return "NO";
    }
    return "YES";
}
