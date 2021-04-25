//Question link: https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int comp = 0, i=0;
        while(num){
            if((num&1)==0)
               comp = comp|(1<<i);
            //cout<<((num&1)==0)<<" "<<comp<<" ";
            num>>=1;
            i++;
        }
        return comp;
    }
};
