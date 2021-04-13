//Question link: https://www.interviewbit.com/problems/permutations/

void all_perm(vector<vector<int>> &v, vector<int> A, int i){
    if(i==A.size()){
       v.push_back(A);
       return;
    }
    for(int j=i; j<A.size(); j++){
        swap(A[i], A[j]);
        all_perm(v, A, i+1);
        swap(A[i], A[j]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> v;
    all_perm(v,A,0);
    return v;
}
