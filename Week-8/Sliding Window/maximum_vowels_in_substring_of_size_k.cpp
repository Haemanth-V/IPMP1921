//Question link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int maxVowels = INT_MIN, vowels = 0, start = 0;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i]))
                vowels++;
            if(i-start+1 == k){
                maxVowels = max(maxVowels, vowels);
                if(isVowel(s[start]))
                    vowels--;
                start++;  
                //cout<<i<<" "<<maxVowels<<"\n";
            }
            
        }
        return maxVowels;
    }
};
