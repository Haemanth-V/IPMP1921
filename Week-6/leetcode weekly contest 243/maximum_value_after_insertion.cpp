//Question link: https://leetcode.com/contest/weekly-contest-243/problems/maximum-value-after-insertion/

class Solution {
public:
    string maxValue(string n, int x) {
        int i=0;
        if(n[0] == '-'){
            int i;
            for(i=0; i<n.length(); i++)
                if(n[i]-'0' > x){
                    n.insert(n.begin()+i, x+'0');
                    break;
                }
            if(i==n.length())
                n.insert(n.end(), x+'0');
        }
        else{
            int i;
            for(i=0; i<n.length(); i++)
            if(n[i]-'0' < x){
                n.insert(n.begin()+i, x+'0');
                break;
            }
            if(i==n.length())
                n.insert(n.end(), x+'0');
        }
        return n;
    }
};
