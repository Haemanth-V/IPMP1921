//Question link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Brute Force
        vector<int> indices(2);
        for(int i=0; i<nums.size(); i++){
            indices[0] = i;
            int j;
            for(j=i+1; j<nums.size() && nums[i]+nums[j] != target; j++);
            if(j!=nums.size()){
                indices[1] = j;
                break;
            }
        }*/
        unordered_map<int, int> nums2;
        vector<int> indices(2);
        for(int i=0; i<nums.size(); i++){
            indices[1] = i;
            auto it = nums2.find(target-nums[i]);
            if(it != nums2.end()){
                indices[0] = it->second;
                break;
            }
            else
                nums2.insert(make_pair(nums[i],i));
        }
        return indices;
    }
};
