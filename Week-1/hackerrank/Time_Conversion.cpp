string timeConversion(string s) {
    /*
     * Write your code here.
     */
    if(s[8] == 'P' && (s[0] != '1' || s[1] != '2')){
        s[0] += 1;
        s[1] += 2;
    }
    else if(s[8] == 'A' && s[0] == '1' && s[1] == '2'){
        s[0] = s[1] = '0';
    }
    s.pop_back();
    s.pop_back();
    return s;
}
