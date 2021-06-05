//Question link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem

int superDigit(string n, int k) {
    string s;
    long sum = 0;
    for(int i=0; i<n.length(); i++)
        sum += n[i]-'0';
    sum *= k;
    if(n.length() == 1)
        return sum;
    return superDigit(to_string(sum), 1);
}
