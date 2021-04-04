string kangaroo(int x1, int v1, int x2, int v2) {
    int t;
    if((x1 > x2 && v1 > v2) || (x1 < x2 && v1 < v2))
       return "NO";
    if(v1 == v2)
        t=0;
    else
        t = (x1 - x2)/(v2 - v1);  //Meet after t secs implies x1 + v1*t = x2 + v2*t
    if(x1+v1*t == x2+v2*t) 
        return "YES";
    return "NO";

}
