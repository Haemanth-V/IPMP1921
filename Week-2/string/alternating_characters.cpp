//Question link: https://www.hackerrank.com/challenges/alternating-characters/problem

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    char c = s[0];
    int dels = 0;
    for(int i=1; i<s.length(); i++){
        if(s[i] == c)
           dels++;
        else
           c = s[i];
    }
    return dels;
}
