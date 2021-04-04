int EuclidGCD(int a, int b){
    if(b==0)
       return a;
    return EuclidGCD(b, a%b);
}

int getTotalX(vector<int> a, vector<int> b) {
    int lcm = a[0], gcd = b[0], count=0;
    for(int i=1; i<a.size(); i++)
        lcm = lcm*a[i]/EuclidGCD(lcm, a[i]);
    for(int i=1; i<b.size(); i++)
        gcd = EuclidGCD(b[i], gcd);
    int t = lcm;
    //cout<<"LCM: "<<lcm<<" GCD: "<<gcd<<"\n";
    while(lcm <= gcd){
        if(gcd%lcm == 0)
            count++;
        lcm += t;
    }
    //we add lcm because say x is divisible by all elements then x+y is also divisible
    //only if y is divisible by all elements. Least value of y is lcm itself.
    return count;
}
