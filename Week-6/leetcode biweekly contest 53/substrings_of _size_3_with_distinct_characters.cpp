//Question link: https://leetcode.com/contest/biweekly-contest-53/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    bool distinct(char a, char b, char c){
        return a != b && b != c && c != a;
    }
    int countGoodSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i+2<s.length(); i++){
            if(distinct(s[i], s[i+1], s[i+2]))
                cnt++;
        }
        return cnt;
    }
};
