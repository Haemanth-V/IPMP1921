//Question link: https://www.hackerrank.com/challenges/beautiful-pairs/problem

/*
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

int beautifulPairs(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int change = 0, pairs = 0, i=0, j=0;
    while(i<A.size() && j<B.size())
        if(A[i] == B[j]){
            pairs++;
            i++;
            j++;
        }
        else if(A[i] > B[j])
           j++;
        else
           i++;
    if(pairs<B.size())
        pairs++;
    else 
        pairs--;
    return pairs;
}
