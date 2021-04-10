//Question link: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int count=0;
    for(int n = i; n<=j; n++){
        int t = n, rev = 0;
        while(t){
            rev = rev*10+t%10;
            t/=10;
        }
        if(abs(n-rev)%k == 0)
            count++;
    }
    return count;
}
