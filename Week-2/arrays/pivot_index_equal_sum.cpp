//Question link: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum = accumulate(nums.begin()+1, nums.end(), 0);
        int left_sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(left_sum == right_sum)
                return i;
            left_sum += nums[i];
            if(i+1<nums.size())
                right_sum -= nums[i+1];
        }
        return -1;
    }
};
