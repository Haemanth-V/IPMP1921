//Question link: https://www.hackerrank.com/challenges/angry-children/problem

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> arr) {
    int minDiff = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i=0; i<=arr.size()-k; i++)
        minDiff = min(minDiff, arr[i+k-1] - arr[i]);
    return minDiff;
}
