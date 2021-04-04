#include <bits/stdc++.h>
 
using namespace std;
 
int get_time(vector<int> a, vector<int> b, vector<int> tm, int n){
    int dep = 0, arrival;
    arrival = a[0] + tm[0];
    for(int i=0; i<n-1; i++){
        dep = max(b[i], arrival+(int)ceil((b[i]-a[i])/2.0));
        arrival = dep + a[i+1] - b[i] + tm[i+1];
    }
    return arrival;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), b(n), tm(n);
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i];
        }
        for(int i=0; i<n; i++){
            cin>>tm[i];
        }
        cout<<get_time(a,b,tm,n)<<"\n";
    }
}
