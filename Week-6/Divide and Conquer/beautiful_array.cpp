//Question link: https://leetcode.com/problems/beautiful-array/

class Solution {
public:
    vector<int> beautifulArray(int n) {
        
        if(n == 1)
            return {1};
        
        vector<int> res;
        vector<int> left = beautifulArray((n+1)/2);
        vector<int> right = beautifulArray(n/2);
        for(int i=0; i<left.size(); i++)
            res.push_back(2*left[i]-1);
        for(int i=0; i<right.size(); i++)
            res.push_back(2*right[i]);
        return res;
    }
    
};

