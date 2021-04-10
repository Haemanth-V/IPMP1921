//Question link: https://www.hackerrank.com/challenges/anagram/problem

// Complete the anagram function below.
int anagram(string s) {
    if(s.length()%2) 
       return -1;
    int count[26] = {0};
    for(int i=0; i<s.length(); i++){
        if(i<s.length()/2)
            count[s[i]-'a']++;
        else
            count[s[i]-'a'] = max(0,count[s[i]-'a']-1);
    }
    return accumulate(count, count+26, 0);
}
