//Question link: https://codeforces.com/contest/1504/problem/B

#include <bits/stdc++.h>

using namespace std;

string flip_bits(string a, string b, int n){
    bool equal;
    int count[] = {0,0};
    equal = (a[0] == b[0]);
    for(int i=0; i<n; i++){
        //cout<<a[i]<<" "<<b[i]<<" "<<equal<<"\n";
        if(a[i] == b[i]){
            if(equal){
                count[a[i]-'0']++;
            }
            else{
                if(count[0] != count[1])
                    return "NO";
                else{
                    equal = !equal;
                    count[0] = 0;
                    count[1] = 0;
                    i--;
                }
            }
        }
        else{
            if(!equal){
                count[a[i]-'0']++;
            }
            else{
                if(count[0] != count[1])
                    return "NO";
                else{
                    equal = !equal;
                    count[0] = 0;
                    count[1] = 0;
                    i--;
                }
            }
        }
    }
    
    if(equal)
        return "YES";
    if(!equal && count[0] == count[1])
        return "YES";
    return "NO";
 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        cout<<flip_bits(a,b,n)<<"\n";
    }
}
