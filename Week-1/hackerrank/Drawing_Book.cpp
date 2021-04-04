int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    int t = ceil((p-1)/2.0);
    return min(t, n/2-t);
}
