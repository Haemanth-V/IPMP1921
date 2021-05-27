//Question link: https://www.hackerrank.com/challenges/jim-and-the-orders/problem

/*
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

bool cmp(vector<int> &a, vector<int> &b){
    int t1 = a[1] + a[2];
    int t2 = b[1] + b[2];
    if(t1 == t2)
       return a[0] < b[0];
    return t1 < t2;
}
