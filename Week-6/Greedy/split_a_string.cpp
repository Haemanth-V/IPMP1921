//Question link: https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, sum = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'R')
                sum++;
            else
                sum--;
            if(sum == 0)
                count++;
        }
        return count;
    }
};
