//Question link: https://www.hackerrank.com/challenges/caesar-cipher-1/problem

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    for(int i=0; i<s.length(); i++){
        if(isalpha(s[i])){
            if(isupper(s[i]))
               s[i] = (s[i]-'A'+k)%26 + 'A';
            else
               s[i] = (s[i]-'a'+k)%26 + 'a';
        }
    }
    return s;

}
