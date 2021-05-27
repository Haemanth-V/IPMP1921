//Question link: https://leetcode.com/problems/fibonacci-number/

//Method 1: O(n)
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};



//Method 2: O(log n)
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        int k;
        if(n%2){
            k = (n+1)/2;
            int t1 = fib(k), t2 = fib(k-1);
            return t1*t1 + t2*t2;
        }
        else{
            k = n/2;
            int t1 = fib(k), t2 = fib(k-1);
            return (2*t2 + t1)*t1;
        }
    }
};
