//Question link: https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i = A.size()-1, j=B.size()-1;
    A.resize(A.size()+B.size());
    int k = A.size()-1;
    while(i>=0 && j>=0){
        if(A[i] > B[j])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }
    
    while(i>=0){
        A[k--] = A[i--];
    }
    
    while(j>=0){
        A[k--] = B[j--];
    }
}
