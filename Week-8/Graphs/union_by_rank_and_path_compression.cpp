//Question link: https://www.interviewbit.com/problems/cycle-in-undirected-graph/

struct subset{
    int parent, rank;
};
int find(subset s[], int i){
    if(s[i].parent != i)
        s[i].parent = find(s, s[i].parent);
    return s[i].parent;
}
void Union(subset s[], int x, int y){
    if(s[x].rank < s[y].rank)
        s[x].parent = y;
    else{
        s[y].parent = x;
        if(s[y].rank == s[x].rank)
           s[x].rank++;
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    subset s[A+1];
    for(int i=1; i<=A; i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    for(int i=0; i<B.size(); i++){
        int x = find(s,B[i][0]);
        int y = find(s,B[i][1]);
        if(x == y)
            return 1;
        Union(s,x,y);
    }
    return 0;
}
