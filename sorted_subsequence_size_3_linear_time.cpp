//Question link: https://leetcode.com/problems/increasing-triplet-subsequence/submissions/

//Method 1: Using extra space
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int smaller[n];
        int min = 0, max = n-1;
        
        for(int i=1; i<n; i++)
            if(nums[i] > nums[min])
                smaller[i] = min;
            else{
                smaller[i] = -1;
                min = i;
            }
        
        for(int i=n-2; i>0; i--)
            if(nums[i] < nums[max]){
                if(smaller[i] != -1)
                     return true;
            }
            else
                max = i;
        return false;
    }
};
