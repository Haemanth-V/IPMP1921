//Question link: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k) {
    int e = 100, i = 0;
    do{
        i = (i+k)%c.size();
        e -= 1 + 2*c[i];
    }while(i!=0);
    return e;

}
