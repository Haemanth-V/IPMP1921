//Question link: https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long Xor = 0;
        for(int i=0; i<nums.size(); i++){
            Xor = Xor^nums[i];
        }
        
        //get rightmost set bit
        Xor = Xor & ~(Xor-1);
        vector<int> res{0,0};
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&Xor)
                res[0] = res[0]^nums[i];
            else
                res[1] = res[1]^nums[i];
        }
        return res;
    }
};
