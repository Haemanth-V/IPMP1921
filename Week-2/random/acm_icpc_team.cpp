//Question link: https://www.hackerrank.com/challenges/acm-icpc-team/problem

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {
    int max = 0, count = 0;
    for(int i=0; i<topic.size()-1; i++){
        string s1 = topic[i];
        for(int j=i+1; j<topic.size(); j++){
            string s2 = topic[j];
            int known = 0;
            for(int k=0; k<s1.length(); k++)
                if(s1[k]=='1' || s2[k]=='1')
                    known++;
            if(max < known){
                max = known;
                count = 1;
            }
            else if(max == known)
                count++;
        }
    }
    return vector<int>{max,count};
}
