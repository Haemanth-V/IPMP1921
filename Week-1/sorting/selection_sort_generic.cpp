#include <bits/stdc++.h>

using namespace std;

template <typename T>
void display(T arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

template <class T>
void selection_sort(T &arr, int n){
    for(int i=0; i<n-1; i++){
        int min = min_element(arr.begin()+i, arr.end()) - arr.begin();
        swap(arr[i],arr[min]);
    }
    display(arr,n);
}


main(){
    vector<int> a1{2,5,4,3,6,7,8,9,1,0,-5,1,2};
    vector<char> a2{'a','z','x','h','t','j','b','y','c'};
    vector<double>a3{-1.1, 5.4, 3.6, 7.2, 0.4, 0, 5.8, 5.2, 4.9};
    cout<<"Sorted a1: ";
    selection_sort(a1, a1.size());
    cout<<"Sorted a2: ";
    selection_sort(a2, a2.size());
    cout<<"Sorted a3: ";
    selection_sort(a3, a3.size());
}