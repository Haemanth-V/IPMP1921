//Question link:

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]*a[1] > b[0]*b[1];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> rot;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                vector<int> t;
                t.push_back(min(cuboids[i][(j+1)%3],cuboids[i][(j+2)%3]));
                t.push_back(max(cuboids[i][(j+1)%3],cuboids[i][(j+2)%3]));
                t.push_back(cuboids[i][j]);
                t.push_back(i);
                rot.push_back(t);
            }
        }
        
        n = 3*n;
        sort(rot.begin(), rot.end(), cmp);
        int dp[n];
        
        for(int i=0; i<n; i++)
            dp[i] = rot[i][2];
        
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(rot[j][0] > rot[i][0] && rot[j][1] > rot[i][1])
                    dp[i] = max(dp[i], dp[j]+rot[i][2]);
        
        return *max_element(dp, dp+n);
    }
};
