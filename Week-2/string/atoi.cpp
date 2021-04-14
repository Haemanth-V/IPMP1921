//Question link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        
        int num=0, sign=1;
        bool read_sign = false;
        for(int i=0; i<s.length(); i++){
            if(!read_sign && isspace(s[i]))
               continue;
            if(s[i] == '-' || s[i] == '+'){
                if(read_sign)
                    break;
                if(s[i] == '-')
                    sign = -1;
                read_sign = true;
            }
            else if(isdigit(s[i])){
               read_sign = true;
               long t = (long)num*10 + s[i]-'0';
               if( t > INT_MAX && sign == 1){
                   num = INT_MAX;
                   break;
               }
               else if(-t < INT_MIN){
                   num = INT_MIN;
                   break;
               }
                else
                    num = t;
            }
            else
                break;
        }
        if(num != INT_MIN)
            num *= sign;
        return num;
    }
};
