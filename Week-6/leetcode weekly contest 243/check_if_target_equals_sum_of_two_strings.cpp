//Question link: https://leetcode.com/contest/weekly-contest-243/problems/check-if-word-equals-summation-of-two-words/

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1 = 0, num2 = 0, target = 0;
        num1 = findNum(firstWord);
        num2 = findNum(secondWord);
        target = findNum(targetWord);
        return num1+num2 == target;
    }
    int findNum(string s){
        int num = 0;
        for(int i=0; i<s.length(); i++)
            num = num*10+s[i]-'a';
        return num;
    }
};
