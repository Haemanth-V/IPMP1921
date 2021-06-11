//Question link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
            if(color[i] == -1)
                if(isBipartite(graph, color, i) == false)
                    return false;
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph, vector<int> &color, int src) {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0; i<graph[u].size(); i++){
                int v = graph[u][i];
                if(color[v] == -1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
                else if(color[v] == color[u])
                    return false;
            }
        }
        return true;
    }
};
