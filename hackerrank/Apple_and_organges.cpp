int getCount(vector<int> v, int pos, int l, int r){
    int count=0;
    for(int i=0; i<v.size(); i++)
       if(pos+v[i] >= l && pos+v[i] <= r)
           count++;
    return count;
}
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
      int count = getCount(apples, a, s, t);
      cout<<count<<"\n";
      count = getCount(oranges, b, s, t);
      cout<<count<<"\n";
}
