//Question link: https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string chk = "hackerrank";
    int j=0;
    for(int i=0; i<s.size() && j<chk.size(); i++){
        if(s[i] == chk[j])
            j++;
    }
    if(j == chk.size())
        return "YES";
    return "NO";
}
