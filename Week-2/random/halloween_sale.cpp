//Question link: https://www.hackerrank.com/challenges/halloween-sale/problem

// Complete the howManyGames function below.
int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int n = 0;
    while(s > 0){
        s -= p;
        if(s>=0)
           n+=1;
        p -= d;
        if(p<m)
           p = m;
    }
    return n;
}
