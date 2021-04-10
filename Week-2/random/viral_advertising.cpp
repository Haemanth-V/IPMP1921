//Question link: https://www.hackerrank.com/challenges/strange-advertising/problem

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int liked = 0, shared = 5;
    while(n--){
        liked += shared/2;
        shared = shared/2*3;
    }
    return liked;
}
