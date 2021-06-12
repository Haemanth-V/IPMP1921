//Question link: https://leetcode.com/problems/course-schedule-ii/

//Time limit exceeded
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> s;
        vector<bool> visited(numCourses, false);
        
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                topSort(prerequisites, numCourses, s, visited, i);
        
        vector<int> order;
        unordered_map<int,int> pos;
        int index= 0;
        while(!s.empty()){
            pos[s.top()] = index++;
            order.push_back(s.top());
            s.pop();
        }
        
        for(int i=0; i<prerequisites.size(); i++){
            if(pos[prerequisites[i][0]] < pos[prerequisites[i][1]])
                return {};
        }
        
        return order;
    }
    void topSort(vector<vector<int>>prereq, int n, stack<int> &s, vector<bool> &visited, int i){
        visited[i] = true;
        for(int j=0; j<prereq.size(); j++){
            if(prereq[j][1] == i && !visited[prereq[j][0]])
                topSort(prereq, n, s, visited, prereq[j][0]);
        }
        s.push(i);
    }
};
