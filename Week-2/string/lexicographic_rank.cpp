//Question link: https://www.interviewbit.com/problems/sorted-permutation-rank/

long mod = 1000003;

long fact(int n){
    if(n<=1)
       return 1;
    return n*fact(n-1);
}

int find_smaller(string A, int i, int n){
    int cnt = 0;
    for(int j=i+1; j<n; j++)
        if(A[i]>A[j])
           cnt++;
    return cnt;
}

int Solution::findRank(string A) {
    
    int n = A.length();
    if(n==1)
       return 1;
    long len_fact = fact(n-1);
    int rank = 1;
    //cout<<len_fact<<" "<<n<<" "<<m<<"\n";
        
    for(int i=0; i<n; i++){
        rank = (rank + find_smaller(A,i,n)*len_fact%mod)%mod;
        if(n-i-1 > 0)
            len_fact /= n-i-1;
    }
    return rank;
}
