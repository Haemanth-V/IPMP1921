int getCount(vector<int> v, int pos, int l, int r){
    int count=0;
    for(int i=0; i<v.size(); i++)
       if(pos+v[i] >= l && pos+v[i] <= r)
           count++;
    return count;
}
vector<int> gradingStudents(vector<int> grades) {
    for(int i=0; i<grades.size(); i++)
        if(grades[i] >= 38 && grades[i]%5 > 2)
            grades[i] += 5-grades[i]%5;
     return grades;
}
