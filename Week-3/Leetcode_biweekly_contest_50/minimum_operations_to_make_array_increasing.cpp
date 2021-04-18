//Question link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sum = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1])
                continue;
            int t =nums[i-1]-nums[i]+1;
            sum += t;
            nums[i] += t;
            //cout<<nums[i]<<" ";
        }
        return sum;
    }
};
