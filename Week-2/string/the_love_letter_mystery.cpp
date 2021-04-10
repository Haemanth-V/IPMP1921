//Question link: https://www.hackerrank.com/challenges/the-love-letter-mystery/problem

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int changes = 0;
    for(int i=0, j=s.length()-1; i<j; i++, j--)
        changes += abs(s[i] - s[j]);
    return changes;
}
