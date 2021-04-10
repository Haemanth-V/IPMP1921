//Question link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count[nums.size()], i;
        for(i=0; i<nums.size(); i++)
            count[i] = 0;
        for(i=0; i<nums.size(); i++){
            if(count[nums[i]] == 1)
                break;
            count[nums[i]]=1;
        }
        return nums[i];
    }
};
