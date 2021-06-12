//Question link: https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen = 0, cost = 0, i=0, j=0;
        while(j < s.size()){
            cost += abs(s[j]-t[j]);
            if(cost <= maxCost){
                maxLen = max(maxLen, j-i+1);
            }
            else{
                while(cost > maxCost){
                    cost -= abs(s[i]-t[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};
