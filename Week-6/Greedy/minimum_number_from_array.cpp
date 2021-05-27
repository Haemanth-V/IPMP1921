//Question link: https://www.hackerrank.com/challenges/marcs-cakewalk/problem

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end(), greater<int>());
    long minCal = 0, t=1;
    for(int i=0; i<calorie.size(); i++){
        minCal += t*calorie[i];
        t*=2;
    }
    return minCal;
}
