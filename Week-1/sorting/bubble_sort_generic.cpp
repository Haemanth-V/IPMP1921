#include <bits/stdc++.h>

using namespace std;


template <typename T>
void display(T arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

template <class T>
void bubble_sort(T &arr, int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
                 swap(arr[j], arr[j+1]);
    display(arr, n);
}

main(){
    vector<int> a1{2,5,4,3,6,7,8,9,1,0,-5,1,2};
    vector<char> a2{'a','z','x','h','t','j','b','y','c'};
    vector<double>a3{-1.1, 5.4, 3.6, 7.2, 0.4, 0, 5.8, 5.2, 4.9};
    cout<<"Sorted a1: ";
    bubble_sort(a1, a1.size());
    cout<<"Sorted a2: ";
    bubble_sort(a2, a2.size());
    cout<<"Sorted a3: ";
    bubble_sort(a3, a3.size());
}