void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
      int count = getCount(apples, a, s, t);
      cout<<count<<"\n";
      count = getCount(oranges, b, s, t);
      cout<<count<<"\n";
}
