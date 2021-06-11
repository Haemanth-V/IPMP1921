//Question link: https://leetcode.com/problems/network-delay-time/


//Method 1: O(V^2) approach
class Solution {
public:
    int minTime(vector<int> times, vector<bool> included){
        int min = INT_MAX, index = -1;
        for(int i=1; i<times.size(); i++)
            if(!included[i] && min > times[i]){
                min = times[i];
                index = i;
            }
        return index;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, INT_MAX);
        vector<bool> included(n+1, false);
        time[k] = 0;
        for(int i=0; i<n-1; i++){
            int u = minTime(time, included);
            if(u == -1)
                return -1;
            included[u] = true;
            for(int j=0; j<times.size(); j++){
                int v = times[j][1], timeVal = times[j][2];
                if(times[j][0] == u && !included[v] && time[v] > time[u]+timeVal)
                    time[v] = time[u]+timeVal;
            }
        }
        int res = *max_element(time.begin()+1, time.end());
        if(res == INT_MAX)
            return -1;
        return res;
    }
};




//Method 2: O(VlogV) approach
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        pq.push(make_pair(0, k));
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(int j=0; j<times.size(); j++){
                int v = times[j][1], timeVal = times[j][2];
                if(times[j][0] == u && time[v] > time[u]+timeVal){
                    time[v] = time[u]+timeVal;
                    pq.push(make_pair(time[v], v));
                }
            }
        }
        int res = *max_element(time.begin()+1, time.end());
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
