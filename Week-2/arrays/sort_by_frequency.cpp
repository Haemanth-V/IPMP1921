//Question link: https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int count[201] = {0};
        vector<int> solution;
        
        for(int i=0; i<nums.size(); i++)
            count[nums[i]+100]++;
        
        while(true){
            int pos = -1;
            for(int i=200; i>=0; i--){
                if(count[i] == 0)
                    continue;
                if(pos == -1 || count[i] < count[pos])
                    pos = i;
            }
            if(pos == -1)
                break;
            while(count[pos]){
                count[pos]--;
                solution.push_back(pos-100);
            }
        }
        return solution;
    }
};
