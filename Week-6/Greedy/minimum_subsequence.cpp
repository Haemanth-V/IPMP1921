//Question link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int rest = 0;
        rest = accumulate(nums.begin(), nums.end(), rest);
        int sum = 0; 
        vector<int> res;
        for(int i=0; i<nums.size() && sum <= rest; i++){
            res.push_back(nums[i]);
            rest -= nums[i];
            sum += nums[i];
        }
        return res;
    }
};
