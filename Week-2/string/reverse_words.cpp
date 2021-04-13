//Question link: https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        int i = s.length()-1;
        string rev;
        while(i>=0){
            string t;
            while(i>=0 && s[i] == ' ')
                i--;
            while(i>=0 && s[i]!=' '){
                t.insert(0,1,s[i]);
                i--;
            }
            if(!t.empty()){
                if(!rev.empty())
                    rev.push_back(' ');
                rev.append(t);
            }
        }
        return rev;
    }
};
