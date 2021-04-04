int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    int max = -1;
    for(int i=0; i<keyboards.size(); i++)
        for(int j=0; j<drives.size(); j++)
            if(keyboards[i]+drives[j] <= b && keyboards[i]+drives[j] > max)
                max = keyboards[i]+drives[j];
    return max;
}
