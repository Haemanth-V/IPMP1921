//Question link: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int XOR = 0, maxK = 0;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++)
            XOR = XOR^nums[i];
        
        int k = pow(2,maximumBit)-1;
        for(int i=1; i<=k; i++){
            if((XOR^maxK) < (XOR^i))
                maxK = i;
        }
        res.push_back(maxK);
        for(int n = nums.size()-1; n>0; n--){
            for(int i=0; (1<<i)<=nums[n]; i++){
               if(nums[n] & (1<<i))
                   maxK = maxK^(1<<i);
            }
            res.push_back(maxK);
        }
        return res;
    }
};
