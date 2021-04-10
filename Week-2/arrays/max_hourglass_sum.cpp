//Question link: https://www.hackerrank.com/challenges/2d-array/problem

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max = INT_MIN;
    for(int i=0; i<arr.size()-2; i++){
        for(int j=0; j<arr[i].size()-2; j++){
            int sum = 0;
            for(int k=j; k<j+3; k++){
              sum += arr[i][k];
              sum += arr[i+2][k];
            }
            sum += arr[i+1][j+1];
            if(max < sum)
              max = sum;
        }
    }
    return max;
}
