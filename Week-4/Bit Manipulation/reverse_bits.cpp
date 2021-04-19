//Question link: https://leetcode.com/problems/reverse-bits/

//Method 1 - O(log n)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = n;
        n = n>>1;
        int size = 31;
        while(n!=0){
            rev = rev<<1 | n&1;
            n = n>>1;
            size--;
        }
        rev = rev<<size;
        return rev;
    }
};

