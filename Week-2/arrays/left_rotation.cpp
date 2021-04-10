//Question link: https://www.hackerrank.com/challenges/array-left-rotation/problem

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> v;
    int i = d;
    do{
        v.push_back(arr[i]);
        i = (i+1)%arr.size();
    }while(i!=d);
    return v;
}
