//Question link: https://www.hackerrank.com/challenges/pangrams/problem

// Complete the pangrams function below.
string pangrams(string s) {
    int count[26]={0};
    int found = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ')
            continue;
        char t = tolower(s[i]);
        if(count[t-'a'] == 0){
            count[t-'a']++;
            found++;
        }
    }
    if(found == 26)
       return "pangram";
    return "not pangram";
}
