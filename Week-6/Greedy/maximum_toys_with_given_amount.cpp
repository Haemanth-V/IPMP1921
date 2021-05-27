//Question link: https://www.hackerrank.com/challenges/mark-and-toys/problem

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */

int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int cost = 0, i;
    for(i=0; i<prices.size() && cost < k; i++)
        cost += prices[i];
    if(cost == k)
        return i;
    return i-1;
}
