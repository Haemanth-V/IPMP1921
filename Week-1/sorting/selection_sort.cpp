#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[min])
               min = j;
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }
}

main(){
    int *arr, n;
    cout<<"Size: ";
    cin>>n;
    arr = new int[n];

    cout<<"Data: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    selection_sort(arr, n);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    delete[] arr;

}