#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l+1, n2 = r-mid;
    int i,j,k;
    int L[n1], R[n2];

    for(i=0; i<n1; i++)
        L[i] = arr[l+i];

    for(i=0; i<n2; i++)
        R[i] = arr[mid+i+1];
    
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r){
    if(l>=r)
        return;
    int mid = l + (r-l)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, r);
}


main(){
    int *arr, n;
    cout<<"Size: ";
    cin>>n;
    arr = new int[n];

    cout<<"Data: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    merge_sort(arr, 0, n-1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    delete[] arr;

}