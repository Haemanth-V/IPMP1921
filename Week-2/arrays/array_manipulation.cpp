//Question link: https://www.hackerrank.com/challenges/crush/problem

long arr[10000001];
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {

  
  long maxElement =0 , sum = 0;
  for(int i=0; i<queries.size(); i++){
        
        arr[queries[i][0]-1]+=queries[i][2];
        arr[queries[i][1]]-=queries[i][2];
  }
  for(int i=0;i<n;i++){
      sum+=arr[i];
      maxElement = max(maxElement,sum);
  }
  return maxElement;
}
