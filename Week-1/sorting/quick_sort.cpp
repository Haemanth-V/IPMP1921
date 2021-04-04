#include <bits/stdc++.h>

using namespace std;

//Hoare's partition using first element as pivot
int partition(int arr[], int low, int high){
    int partition = arr[low];
    int l = low+1, r = high;

    while(true){
        while(arr[l] <= partition)
            l++;
        while(arr[r] > partition)
            r--;
        if(l>=r)
           break;
        swap(arr[l], arr[r]);
    }
    swap(arr[low], arr[r]);
    return r;
}

void quick_sort(int arr[], int low, int high){
    if(low >= high)
        return;
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi);
    quick_sort(arr, pi+1, high);
}


main(){
    int *arr, n;
    cout<<"Size: ";
    cin>>n;
    arr = new int[n];

    cout<<"Data: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    quick_sort(arr, 0, n-1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    delete[] arr;

}