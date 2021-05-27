//Question link: https://www.hackerrank.com/challenges/greedy-florist/problem

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end(), greater<int>());
    int t=1, cost = 0, cnt = 1;
    for(int i=0; i<c.size(); i++, cnt++){
        if(cnt <= k)
            cost += t*c[i];
        else{
            cnt = 0;
            t++;
            i--;
        }
    }
    return cost;
}
