//Question link: https://www.hackerrank.com/challenges/sparse-arrays/problem

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> cnt;
    for(int i=0; i<queries.size(); i++)
        cnt.push_back(count(strings.begin(), strings.end(), queries[i]));
    return cnt;
}
