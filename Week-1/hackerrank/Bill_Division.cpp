void bonAppetit(vector<int> bill, int k, int b) {
    int t = b - accumulate(bill.begin(), bill.end(), -bill[k])/2;
    if(t == 0)
       cout<<"Bon Appetit";
    else
       cout<<t;

}
