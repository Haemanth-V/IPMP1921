#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left < n && arr[largest] < arr[left])
        largest = left;

    if(right < n && arr[largest] < arr[right])
        largest = right;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void heap_sort(int arr[], int n){

    //construct max heap
    for(int i=n/2-1; i>=0; i--)
        heapify(arr,i,n);
    
    //sort
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
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
    
    heap_sort(arr, n);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    delete[] arr;

}