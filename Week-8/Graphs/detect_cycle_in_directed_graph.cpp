//Question link: https://www.interviewbit.com/problems/cycle-in-directed-graph/

//Using DFS
bool hasCycle(vector<vector<int> > &B, int v, vector<bool> &visited, vector<bool> &recStack){
    if(!visited[v]){
        visited[v] = true;
        recStack[v] = true;
        for(int i=0; i<B.size(); i++){
            if(B[i][0] == v){
                if(recStack[B[i][1]])
                    return true;
                if(!visited[B[i][1]] && hasCycle(B, B[i][1], visited, recStack))
                     return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1);
    vector<bool> recStack(A+1);
    for(int i=0; i<=A; i++){
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i=1; i<=A; i++){
        if(hasCycle(B, i, visited, recStack))
            return 1;
    }
    return 0;
}
