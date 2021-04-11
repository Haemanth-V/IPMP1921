//Question link: https://www.hackerrank.com/challenges/non-divisible-subset/problem


int longest_subset(int rem[], int i, int k){
    if(i>k-i)
        return 0;
    if(i == k-i){
        if(rem[i] > 0)
           return 1;
        else
           return 0;
    }
    int t = longest_subset(rem, i+1, k);
    return max(t+rem[i], t+rem[k-i]);
}

int nonDivisibleSubset(int k, vector<int> s) {
    int rem[100] = {0};
    for(int i=0; i<s.size(); i++){
      rem[s[i]%k]++;
      //cout<<s[i]<<" "<<s[i]%k<<" "<<rem[s[i]%k]<<"\n";
    }
    int res = longest_subset(rem, 1, k);
    if(rem[0] > 0)
        res+=1;
    return res;
}
