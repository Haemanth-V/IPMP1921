//Question link: https://www.interviewbit.com/problems/path-in-directed-graph/

//Using BFS
int Solution::solve(int A, vector<vector<int> > &B) {
    int start = 1, end = A;
    queue<int> q;
    vector<bool> visited(A, false);
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(i == end)
            return 1;
        for(int j=0; j<B.size(); j++){
            if(B[j][0] == i && !visited[B[j][1]]){
                q.push(B[j][1]);
                visited[i] = true;
            }
        }
    }
    return 0;
}
