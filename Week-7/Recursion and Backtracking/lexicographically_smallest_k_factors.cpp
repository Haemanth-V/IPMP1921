//Question link: https://www.hackerrank.com/challenges/k-factorization/problem

bool kFactorization(vector<int> A, int n, vector<int> &res){
    res.push_back(n);
    if(n == 1)
        return true;
    for(int i=0; i<A.size(); i++){
        if(n%A[i] == 0){
            if(kFactorization(A, n/A[i], res))
                return true;
            else
                res.clear();
        }
    }
    return false;
    
}

vector<int> kFactorization(int n, vector<int> A) {
    //cout<<n<<"\n";
    vector<int> res;
    sort(A.begin(), A.end(), greater<int>());
    bool ans = kFactorization(A, n, res);
    reverse(res.begin(), res.end());
    if(ans)
        return res;
    return {-1};
}
