//Question link: https://www.hackerrank.com/challenges/the-power-sum/problem


int powerSum(int X, int N, int i=1) {
    if(X < 0)
        return 0;
    if(X == 0)
        return 1;
    if(pow(i,N) > X)
        return 0;
    return powerSum(X, N, i+1) + powerSum(X-pow(i,N), N, i+1); //exclude ith number or include it
}
