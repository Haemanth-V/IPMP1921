//Question link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        for(int i=1; i<=n-1; i++){
            for(int j=0; j<times.size(); j++){
                int u = times[j][0];
                int v = times[j][1];
                int timeVal = times[j][2];
                if(time[u] != INT_MAX && time[u]+timeVal < time[v])
                    time[v] = time[u] + timeVal;
            }
        }
        int res = *max_element(time.begin()+1, time.end());
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
