//Question link: https://www.hackerrank.com/challenges/gem-stones/problem

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int minerals = 0;
    for(int i=0; i<arr[0].length(); i++){
        bool found = true;
        char c = arr[0][i];
        int max = count(arr[0].begin(), arr[0].end(), c);
        for(int j=1; j<arr.size(); j++){
            int t = count(arr[j].begin(), arr[j].end(), c);
            if(t == 0){
                found = false;
                break;
            }
            else
               max = min(max, t);
        }
        if(found)
            minerals+=max;
        arr[0].erase(remove(arr[0].begin(), arr[0].end(), c), arr[0].end());
        i--;
    }
    return minerals;
}
