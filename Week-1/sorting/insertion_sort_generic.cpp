#include <bits/stdc++.h>

using namespace std;

template <typename T>
void display(T arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

template <class T>
void insertion_sort(T arr[], int n){
    for(int i=1; i<n; i++){
        T t = arr[i];
        int j;
        for(j=i-1; j>=0 && t<arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = t;
    }
    display(arr, n);
}

main(){
    int a1[] = {2,5,4,3,6,7,8,9,1,0,-5,1,2};
    char a2[] = {'a','z','x','h','t','j','b','y','c'};
    double a3[] = {-1.1, 5.4, 3.6, 7.2, 0.4, 0, 5.8, 5.2, 4.9};
    cout<<"Sorted a1: ";
    insertion_sort(a1, sizeof(a1)/sizeof(int));
    cout<<"Sorted a2: ";
    insertion_sort(a2, sizeof(a2)/sizeof(char));
    cout<<"Sorted a3: ";
    insertion_sort(a3, sizeof(a3)/sizeof(double));
}