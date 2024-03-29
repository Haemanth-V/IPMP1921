//Question link: https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^y;
        int count=0;
        while(diff){
            diff &= diff-1;
            count++;
        }
        return count;
    }
};
