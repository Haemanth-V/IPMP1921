//Question link: https://leetcode.com/problems/first-missing-positive/submissions/

//Method 1: Using extra space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++)
            hash[nums[i]]++;
        int n=1;
        while(hash.find(n) != hash.end())
            n++;
        return n;
    }
};
