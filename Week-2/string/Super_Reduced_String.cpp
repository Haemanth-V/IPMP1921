//Question link: https://www.hackerrank.com/challenges/reduced-string/problem

string superReducedString(string s) {
    for(int i=0; i+1<s.length(); i++){
        int j=i+1;
        if(s[i] == s[j]){
            while(s[i]==s[j] && j<s.length()){
               s.erase(s.begin()+j);
               s.erase(s.begin()+i);
            }
            i = -1;
        }  
        if(s.empty())
           return "Empty String";
    }
    return s;
}
