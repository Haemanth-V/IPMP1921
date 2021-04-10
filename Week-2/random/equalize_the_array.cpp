//Question link: https://www.hackerrank.com/challenges/equality-in-a-array/problem

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    int max = 0, n = arr.size();
    while(arr.size() > 0){
        int i = arr[0];
        int t = count(arr.begin(), arr.end(), i);
        if(max < t)
           max = t;
        arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
    }
    return n-max;
}
