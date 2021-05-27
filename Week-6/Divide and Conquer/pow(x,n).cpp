//Question link: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n == 0)
            return res;
        if(n%2)
            if(n>0)
                res = x;
            else
                res = 1/x;
        double t = myPow(x,n/2);
        res = res*t*t;
        return res;
    }
};
