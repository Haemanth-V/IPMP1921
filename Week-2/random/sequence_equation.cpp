//Question link: https://www.hackerrank.com/challenges/permutation-equation/problem

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    
    vector<int> sequence;
    for(int i=1; i<=p.size(); i++){
       int j = find(p.begin(), p.end(), i) - p.begin() + 1;
       j = find(p.begin(), p.end(), j) - p.begin() + 1;
       sequence.push_back(j);
    }
    return sequence;

}
