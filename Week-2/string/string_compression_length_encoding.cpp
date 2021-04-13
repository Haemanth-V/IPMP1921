//Question link: https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        
        for(int i=0; i<chars.size()-1; i++){
            char c = chars[i];
            int j=i+1;
            while(j<chars.size() && chars[j]==c)
                j++;
            if(j-i > 1){
                string t = to_string(j-i);
                chars.erase(chars.begin()+i+1, chars.begin()+j);
                for(int k=0; k<t.size(); k++)
                    chars.insert(chars.begin()+i+k+1,t[k]);
                i+=t.length();

            }
        }
        return chars.size();
    }
};
