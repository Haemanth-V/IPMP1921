//Question link: https://www.interviewbit.com/problems/next-smallest-palindrome/

string Solution::solve(string n) {
        string s;
        int i;
        
        //All 9s
        for(i=0; i<n.length() && n[i] == '9'; i++);
        if(i==n.length()){
            s = "1";
            s.insert(1, n.length()-1, '0');
            s.push_back('1');
            return s;
        }
        
        for(i=0; i<n.length()/2; i++){
            s.push_back(n[i]);
        }
        string t = s;
        reverse(t.begin(), t.end());
        if(n.length()%2)
            s.push_back(n[n.length()/2]);
        s.insert(n.length()/2 + n.length()%2, t);
        //cout<<s<<"\n";
        if(s.compare(n)<=0){
            i = n.length()/2 + n.length()%2 -1;
            while(s[i] == '9'){
                i--;
            }
            s[i]+=1;
            if(s.length()-i-1 != i)
                s[s.length()-i-1]+=1;
            for(int j=i+1; j<s.length()-i-1; j++)
               s[j] = '0';
        }
        
        return s;
}
