//Question link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int find(vector<int> parent, int i){
        if(parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }
    void Union(vector<int> &parent, int x, int y){
        parent[x] = y;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n, -1);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(isConnected[i][j] == 1){
                    //cout<<i<<" "<<parent[i]<<" "<<j<<" "<<parent[j]<<endl;
                    int x = find(parent, i);
                    int y = find(parent, j);
                    if(x!=y)
                        Union(parent, x, y);
                    
                    //cout<<i<<" "<<parent[i]<<" "<<j<<" "<<parent[j]<<endl;
                }
        // for(int i=0; i<n; i++)
        //     cout<<i<<" "<<parent[i]<<'\n';
        set<int> s;
        for(int i=0; i<n; i++){
            //cout<<i<<" "<<parent[i]<<'\n';
            int t = find(parent, i);
            //cout<<t<<" ";
            s.insert(t);
        }
        return s.size();
    }
};
