//Question link: 

//Divide and conquer - Timed out
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return getmaxscore(nums, 0, nums.size()-1, nums.size()-1);
    }
    int findMaxCoins(vector<int> nums, int l, int r){
        
        int maxCoins = 0;
        for(int i=l+1; i<r; i++){
            int left = findMaxCoins(nums, l, i);
            int right = findMaxCoins(nums, i, r);
            int coins = left+right;
            if(l==0 && r == nums.size()-1)
                coins += nums[i];
            else
                coins += nums[l]*nums[i]*nums[r];
            maxCoins = max(maxCoins, coins);
        }
        
        return maxCoins;
    }
};
