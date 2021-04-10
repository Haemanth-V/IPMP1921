//Question link: https://www.hackerrank.com/challenges/minimum-distances/problem

// Complete the minimumDistances function below.
int minimumDistances(vector<int> a) {
    int min = -1;
    for(int i=0; i<a.size()-1; i++){
        for(int j=i+1; j<a.size(); j++)
            if(a[i] == a[j]){
                if(min == -1 || min > j-i)
                   min = j-i;
                break;
            }
        if(min == 1)
            break;
    }
    return min;
}
