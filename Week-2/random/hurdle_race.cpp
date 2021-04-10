//Question link: https://www.hackerrank.com/challenges/the-hurdle-race/problem

int hurdleRace(int k, vector<int> height) {
    return max(0, *max_element(height.begin(), height.end()) - k);
}
