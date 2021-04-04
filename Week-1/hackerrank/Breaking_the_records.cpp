vector<int> breakingRecords(vector<int> scores) {
    int max=scores[0], min=scores[0];
    vector<int> records_broken{0,0};
    for(int i=1; i<scores.size(); i++){
        if(scores[i] > max){
            max = scores[i];
            records_broken[0]++;
        }
        else if(scores[i] < min){
            min = scores[i];
            records_broken[1]++;
        }
    }
    return records_broken;
}
