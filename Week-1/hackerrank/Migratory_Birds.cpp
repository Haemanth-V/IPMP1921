int migratoryBirds(vector<int> arr) {
     int count[6] = {0};
     for(int i=0; i<arr.size(); i++)
         count[arr[i]]++;
     return max_element(count, count+6) - count;
}
