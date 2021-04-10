//Question link: https://www.hackerrank.com/challenges/cut-the-sticks/problem

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> v;
    while(arr.size() != 0){
        v.push_back(arr.size());
        int i = *min_element(arr.begin(), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
    }
    return v;
}
