//Question link: https://leetcode.com/problems/first-unique-character-in-a-string/

//Method 1
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        vector<char> uniq;
        for(int i=0; i<s.length(); i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a']== 1)
                uniq.push_back(s[i]);
            else if(count[s[i]-'a'] == 2)
                uniq.erase(find(uniq.begin(), uniq.end(), s[i]));
        }
        if(uniq.size() == 0)
            return -1;
        return find(s.begin(), s.end(), uniq[0]) - s.begin();
    }
};

//Method 2
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(int i=0; i<s.length(); i++)
            count[s[i]-'a']++;
        for(int i=0; i<s.length(); i++)
            if(count[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};
