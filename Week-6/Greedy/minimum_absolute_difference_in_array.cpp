//Question link: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem

/*
 * Complete the 'minimumAbsoluteDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min = INT_MAX;
    for(int i=0; i<arr.size()-1; i++)
        if(min > arr[i+1]-arr[i])
            min = arr[i+1]-arr[i];
    return min;
    
}
