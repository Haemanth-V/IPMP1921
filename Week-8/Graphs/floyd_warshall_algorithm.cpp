//Question link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        int time[n+1][n+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                time[i][j] = INT_MAX;
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int timeVal = times[i][2];
            time[u][v] = timeVal;
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(time[i][k] != INT_MAX && time[k][j] != INT_MAX && time[i][j] > time[i][k] + time[k][j])
                   time[i][j] = time[i][k] + time[k][j];     
        }
        // for(int i=1; i<=n; i++)
        //     cout<<src<<" "<<i<<" "<<time[src][i]<<"\n";
        time[src][src] = 0;
        int res = *max_element(time[src]+1, time[src]+n+1);
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
