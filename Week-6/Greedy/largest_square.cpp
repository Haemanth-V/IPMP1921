//Question link: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> sides(rectangles.size());
        for(int i=0; i<rectangles.size(); i++)
            sides[i] = min(rectangles[i][0], rectangles[i][1]);
        return count(sides.begin(), sides.end(), *max_element(sides.begin(), sides.end()));
    }
};
