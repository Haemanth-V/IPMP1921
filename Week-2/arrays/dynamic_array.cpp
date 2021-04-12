//Question link: https://www.hackerrank.com/challenges/dynamic-array/problem


vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);
    vector<int> results;
    int lastAnswer = 0;
    for(int i=0; i<queries.size(); i++){
        int x = queries[i][1], y = queries[i][2];
        int idx = (x^lastAnswer)%n;
        if(queries[i][0] == 1)
            arr[idx].push_back(y);
        else{ 
            lastAnswer = arr[idx][y%arr[idx].size()];
            results.push_back(lastAnswer);
        }
        
    } 
    return results;
}
