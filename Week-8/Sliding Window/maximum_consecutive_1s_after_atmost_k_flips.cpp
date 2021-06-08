//Question link: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max1 = 0, start = 0, zeroes = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zeroes++;
            if(zeroes > k){
                //cout<<i<<endl;
                max1 = max(max1, i-start);
                if(nums[start] == 0)
                    zeroes--;
                start++;
            }
        }
        if(zeroes <= k)
            max1 = max(max1, (int)nums.size()-start);
        return max1;
    }
};
