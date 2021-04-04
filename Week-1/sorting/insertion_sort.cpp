#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        int t = arr[i], j;
        for(j=i-1; j>=0 && t<arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = t;
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
    
    insertion_sort(arr, n);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    delete[] arr;

}