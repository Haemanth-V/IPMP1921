//Question link: https://www.hackerrank.com/challenges/luck-balance/problem

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */
 
 bool cmp(vector<int> &a, vector<int> &b){
     return a[0] > b[0];
 }

int luckBalance(int k, vector<vector<int>> contests) {
    int luck = 0;
    sort(contests.begin(), contests.end(), cmp);
    for(int i=0; i<contests.size(); i++){
        //cout<<contests[i][0]<<" "<<contests[i][1]<<"\n";
        if(contests[i][1] == 0)
            luck += contests[i][0];
        else if(k>0){
            k--;
            luck += contests[i][0];
        }
        else
            luck -= contests[i][0];
    }
    return luck;
}
