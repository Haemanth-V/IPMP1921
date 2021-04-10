//Question link: https://www.hackerrank.com/challenges/weighted-uniform-string/problem

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    unordered_set<int> weights;
    int wt = 0;
    char c = s[0];
    for(int i=0; i<s.size(); i++){
        if(s[i] == c){
            wt += s[i]-'a'+1;
        }
        else{
            c = s[i];
            wt = s[i]-'a'+1;
        }
        weights.insert(wt);
    }
    
    vector<string> ans;
    for(int i=0; i<queries.size(); i++)
        if(weights.find(queries[i]) == weights.end())
           ans.push_back("No");
        else
           ans.push_back("Yes");
           
    return ans;
}
