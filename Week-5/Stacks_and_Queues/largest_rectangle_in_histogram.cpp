//Question link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
    
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0, i = 0;
        for(i=0; i<heights.size(); i++){
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i);
            else{
                int j = st.top();
                st.pop();
                int area = heights[j];
                if(st.empty())
                    area *= i;
                else
                    area*= i-st.top()-1;
                max_area = max(max_area, area);
                i--;
            }
        }
        while(!st.empty()){
            int j = st.top();
            st.pop();
            int area = heights[j];
            if(st.empty())
                area *= i;
            else
                area*= i-st.top()-1;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
