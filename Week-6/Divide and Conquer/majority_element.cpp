//Question link: https://leetcode.com/problems/majority-element/

//Method 1 - Divide and conquer - O(nlgn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size()-1);
    }
    int majority(vector<int> &nums, int l, int r){
        if(l==r)
            return nums[l];
        int mid = (l+r)/2;
        int left = majority(nums, l, mid);
        int right = majority(nums, mid+1, r);
        if(left == right)
            return left;
        int leftCnt = 0, rightCnt = 0;
        for(int i=l; i<=r; i++)
            if(nums[i] == left)
                leftCnt++;
            else if(nums[i] == right)
                rightCnt++;
        if(leftCnt > rightCnt)
            return left;
        return right;
    }
};




//Method 2 - Boyre Moore's Voting Algorithm
//majority eliminate always exists - so need not verify if the candidate is a majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_idx = 0, maj_count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[maj_idx])
                maj_count++;
            else
                maj_count--;
            if(maj_count == 0){
                maj_idx = i;
                maj_count = 1;
            }
        }
        return nums[maj_idx];
    }
};
