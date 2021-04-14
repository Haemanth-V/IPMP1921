//Question link:

//method 1: 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        vector<char> res;
        int max = 1;
        for(int i=0; i<s.length(); i++){
            auto it = find(res.begin(), res.end(), s[i]);
            if(it != res.end()){
                if(max < res.size())
                    max = res.size();
                res.erase(res.begin(), it+1);
            }
            res.push_back(s[i]);
        }
        if(max < res.size())
            max = res.size();
        return max;
    }
};

//Method 2: Sliding window O(n) time

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        vector<int> index(256, -1);
        int len = 1, window_start = 0;
        for(int i=0; i<s.length(); i++){
            window_start  = max(window_start, index[s[i]]+1); 
            len = max(len, i-window_start+1);
            index[s[i]] = i;
        }
        return len;
    }
};
