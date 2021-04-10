//Question link: https://www.hackerrank.com/challenges/mars-exploration/problem

// Complete the marsExploration function below.
int marsExploration(string s) {
    int count=0;
    for(int i=0; i<s.size(); i++)
        if(i%3==1){
            if(s[i] != 'O')
                count++;
        }
        else if(s[i] != 'S')
            count++;
    return count;
}
