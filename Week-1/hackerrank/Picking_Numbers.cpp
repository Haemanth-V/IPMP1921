int pickingNumbers(vector<int> a) {
    int count[100] = {0};
    for(int i=0; i<a.size(); i++)
        count[a[i]]++;
    int max = 0;
    for(int i=1; i<99; i++)
       if(max < count[i] + count[i+1])
           max = count[i] + count[i+1];
    return max;
}
