#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<char> &arr, int n){
    int count[256] = {0};
    int j;
    for(char c: arr)
        count[c]++;

    j = 0;
    for(int i=0; i<256; i++){
        for(int k=0; k<count[i]; k++)
            arr[j++] = i;
    }
}

main(){
    vector<char> arr;
    char c;
    int n;
    cout<<"Size: ";
    cin>>n;

    cout<<"Data: ";
    for(int i=0; i<n; i++){\
        cin>>c;
        arr.push_back(c);
    }
    
    counting_sort(arr, n);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
}