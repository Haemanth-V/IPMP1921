//Question link: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem

/*
 * Complete the 'decentNumber' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void decentNumber(int n) {
    vector<char> dec;
    int n3 = 0, n5 = n;
    for(int i=0; i<n; i++)
        dec.push_back('5');
    if(n5%3 == 0)
        for(int i=0; i<n; i++)
            cout<<dec[i];
    else{
        int i=n-1;
        while(n3%5 || n5%3){
            for(int c=1; c<=5 && i>=0; c++, i--)
                dec[i] = '3';
            n5-=5;
            n3+=5;
            if(i<0)
                break;
        }
        if(n3>=0 && n5>=0)
            for(int i=0; i<n; i++)
                cout<<dec[i];
        else
            cout<<"-1";
    }
    cout<<"\n";
}
