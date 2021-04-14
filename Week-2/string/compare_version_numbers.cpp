//Question link: https://www.interviewbit.com/problems/compare-version-numbers/

int Solution::compareVersion(string A, string B) {
    int i,j;
    for(i=0, j=0; i<A.length() && j<B.length(); i++,j++){
        double n1 = 0;
        while(i<A.length() && A[i]!='.'){
            n1 = n1*10+A[i]-'0';
            i++;
        }
        
        double n2 = 0;
        while(j<B.length() && B[j]!='.'){
            n2 = n2*10 + B[j]-'0';
            j++;
        }
        
        if(n1 < n2)
            return -1;
        if(n1 > n2)
            return 1;
    }
    if((int)A.length()-i < (int)B.length()-j){
       for(int k=j; k<B.length(); k++)
         if(isdigit(B[k]) && B[k] > '0')
             return -1;
    }
    else if((int)A.length()-i > (int)B.length()-j){
        for(int k=i; k<A.length(); k++)
         if(isdigit(A[k]) && A[k] > '0')
             return 1;
    }
    
    return 0;
}
