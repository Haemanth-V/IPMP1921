//Question link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector< vector<int> > v;
        for(int i=n-1; i>=2; i--){
            if(i!=n-1 && nums[i]==nums[i+1])
                continue;
            int j = 0, k = i-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                   if(j==0 || k==i-1 || j-1>=0 && nums[j-1] != nums[j] || k+1 < i && nums[k+1]!= nums[k]){
                     vector<int> triplet{nums[j], nums[k], nums[i]};
                     v.push_back(triplet);
                     
                   }
                   j++;
                   k--;
                }
                else if(sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return v;
    }
};
