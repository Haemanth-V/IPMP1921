//Question link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        for(int i=0; i<s1.length(); i++)
            count[s1[i]-'a']++;
    
        for(int i=0; i<s2.length(); i++){
            if(count[s2[i]-'a'] > 0){
                vector<int> cnt;
                cnt = count;
                bool flag = true;
                for(int j=0; j<s1.size(); j++){
                    if(j+i >= s2.size() || cnt[s2[j+i]-'a'] <= 0){
                        flag = false;
                        break;
                    }
                    cnt[s2[j+i]-'a']--;
                }
                if(flag)
                    return true;
            }
        }
            
        return false;
    }
    
};
