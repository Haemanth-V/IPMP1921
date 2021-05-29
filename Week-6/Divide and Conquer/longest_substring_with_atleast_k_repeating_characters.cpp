//Question link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubStr(s, 0, s.length()-1, k);
        
    }
    
    int longestSubStr(string s, int l, int r, int k){
        if(r-l+1 < k || l > r)
            return 0;
        int count[26] = {0};
        for(int i=l; i<=r; i++)
            count[s[i]-'a']++;
        int mid = l; 
        while(mid <= r && count[s[mid]-'a'] >= k)
            mid++;
        if(mid > r)
            return r-l+1;
        return max(longestSubStr(s, l, mid-1, k), longestSubStr(s, mid+1, r, k));
    }
};
