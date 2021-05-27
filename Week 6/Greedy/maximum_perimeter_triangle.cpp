//Question link: https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */
bool formsTriangle(int a, int b, int c){
    return a+b > c && a+c > b && b+c > a;
}

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    sort(sticks.begin(), sticks.end(), greater<int>());
    long maxPer = 0;
    vector<int> sides(3);
    for(int i=0; i+2<sticks.size(); i++){
        long sum = (long)sticks[i] + sticks[i+1] + sticks[i+2];
        if(formsTriangle(sticks[i], sticks[i+1], sticks[i+2]) && maxPer < sum){
            maxPer = sum;
            sides[0] = sticks[i+2];
            sides[1] = sticks[i+1];
            sides[2] = sticks[i];
        }
    }
    if(maxPer > 0)
        return sides;
    return {-1};
}
