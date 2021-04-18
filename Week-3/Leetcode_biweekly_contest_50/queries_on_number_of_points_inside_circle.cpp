//Question link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int count = 0;
            for(int j=0; j<points.size(); j++){
                if(sqrt(pow(queries[i][0]-points[j][0],2)+pow(queries[i][1]-points[j][1],2)) <= queries[i][2])
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
