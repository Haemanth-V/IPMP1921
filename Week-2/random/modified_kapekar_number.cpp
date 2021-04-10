//Question link: https://www.hackerrank.com/challenges/kaprekar-numbers/problem

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool found = false;
    for(int n=p; n<=q; n++){
        int i = 1;
        int d = log(n)/log(10)+1;
        //cout<<n<<" "<<d<<"\n";
        long l = (long)n*n, r = 0;
        while(i<=d){
            r += l%10*pow(10,i-1);
            l /= 10;
            i++;
        }
        //cout<<l<<" "<<r<<" "<<n<<"\n";
        if(n == 1 || (r!=0 && l+r == n)){
            cout<<n<<" ";
            found = true;
        }
    }
    if(!found)
        cout<<"INVALID RANGE";
}
