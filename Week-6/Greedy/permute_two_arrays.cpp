//Question link: https://www.hackerrank.com/challenges/two-arrays/problem

/*
 * Complete the 'twoArrays' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 *  3. INTEGER_ARRAY B
 */

string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    for(int i=0; i<A.size(); i++)
        if(A[i] +B[i] < k)
            return "NO";
    return "YES";
}
