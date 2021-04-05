//Question link: https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    int swap_pos1 = -1;
    for(int i=0; i<A.size()-1; i++){
        if(A[i] < A[i+1])
            swap_pos1 = i;
    }
    if(swap_pos1 == -1)
        sort(A.begin(), A.end());
    else{
        int swap_pos2, min = INT_MAX; 
        for(int i=swap_pos1+1; i<A.size(); i++){
            if(A[i]<min && A[i]>A[swap_pos1]){
                min = A[i];
                swap_pos2 = i;
            }
        }
        swap(A[swap_pos1], A[swap_pos2]);
        sort(A.begin()+swap_pos1+1, A.end());
    }
    return A;
}
