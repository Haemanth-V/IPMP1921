//Question link: https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> res;
        for(int i=0; i<expression.size(); i++){
            if(!isdigit(expression[i])){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(int j=0; j<left.size(); j++)
                   for(int k=0; k<right.size(); k++)
                       switch(expression[i]){
                           case '+': res.push_back(left[j]+right[k]); break;
                           case '-': res.push_back(left[j]-right[k]); break;
                           case '*': res.push_back(left[j]*right[k]); break;
                       }
                
            }
        }
        
        if(res.size() == 0)
            res.push_back(atoi(expression.c_str()));
        
        return res;
    }
};
