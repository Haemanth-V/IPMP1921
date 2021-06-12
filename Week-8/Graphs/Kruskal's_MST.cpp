//Question Link: https://www.interviewbit.com/problems/commutable-islands/

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
        if(s[x].rank == s[y].rank)
            s[x].rank++;
    }
}
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    subset s[A+1];
    for(int i=1; i<=A; i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    int e = 0, cost = 0;
    sort(B.begin(), B.end(), cmp);
    for(int i=0; i<B.size() && e<A-1; i++){
        int x = find(s, B[i][0]);
        int y = find(s, B[i][1]);
        if(x != y){
            e++;
            cost += B[i][2];
            Union(s, x, y);
        }
    }
    return cost;
}
