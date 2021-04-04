vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> elements;
    int n = a.size();
    for(int i=0; i<queries.size(); i++)
        elements.push_back(a[(queries[i]-k+(k/n+1)*n)%n]);
    return elements;
}
