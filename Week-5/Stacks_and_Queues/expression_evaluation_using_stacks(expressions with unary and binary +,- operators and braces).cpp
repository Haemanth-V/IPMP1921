//Question Link: https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        bool unary = true;
        stack<long> val;
        stack<char> ops;
        for(int i=0; i<s.length(); i++){
            if(isspace(s[i]))
                continue;
            if(isdigit(s[i])){
                long num = 0;
                while(i<s.length() && isdigit(s[i])){
                    num = num*10 + s[i] - '0';
                    i++;
                }
                val.push(num);
                unary = false;
                i--;
            }
            else if(s[i] == '('){
                ops.push(s[i]);
                unary = true;
            }
            else{
                while(!ops.empty() && ops.top() != '('){
                    long a = val.top();
                    val.pop();
                    long b = val.top();
                    val.pop();
                    switch(ops.top()){
                        case '+': val.push(b+a);
                                  break;
                        case '-': val.push(b-a);
                                  break;
                    }
                    ops.pop();
                }
                if(!ops.empty() && s[i] == ')')
                    ops.pop();
                if(unary && s[i] != ')')
                    val.push(0);
                if(s[i] == '+' || s[i] == '-'){
                    ops.push(s[i]);
                    unary = !unary;
                }
            }
        }
        while(!ops.empty()){
            long a = val.top();
            val.pop();
            long b = val.top();
            val.pop();
            switch(ops.top()){
                case '+': val.push(b+a);
                          break;
                case '-': val.push(b-a);
                          break;
            }
            ops.pop();
        }
        return val.top();
    }
};
