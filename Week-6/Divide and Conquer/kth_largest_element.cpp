//Question link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kthLargest(nums, 0, nums.size()-1, k);
    }
    int partition(vector<int> &nums, int l, int r){
        int i = l-1;
        for(int j=l; j<=r; j++){
            if(nums[j] <= nums[r]){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i;
    }
    int kthLargest(vector<int> &nums, int l, int r, int k){
        int pi = rand()%(r-l+1)+l;
        swap(nums[pi], nums[r]);
        int pivotPos = partition(nums, l, r);
        if(pivotPos == nums.size()-k)
            return nums[pivotPos];
        else if(pivotPos < nums.size()-k)
            return kthLargest(nums, pivotPos+1, r, k);
        else
            return kthLargest(nums, l, pivotPos-1, k);
    }
};
