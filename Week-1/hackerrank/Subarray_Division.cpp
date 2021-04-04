int birthday(vector<int> s, int d, int m) {
    int count = 0;
    for(int i=0; i+m<=s.size();  i++)
        if(accumulate(s.begin()+i, s.begin()+i+m, 0) == d)
            count++;
    return count;
}
