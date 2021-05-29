//Question link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        kclosestpoints(points, 0, points.size()-1, k);
        for(int i=0; i<k; i++)
            res.push_back(points[i]);
        return res;
    }
    void kclosestpoints(vector<vector<int>> &v, int l, int r, int k){
        if(l >= r)
            return;
        int pi = rand()%(r-l+1)+l;
        swap(v[l], v[pi]);
        int mid = partition(v, l, r);
        int leftLength = mid - l + 1;
        if (k < leftLength)
            kclosestpoints(v, l, mid, k);
        else if (k > leftLength)
            kclosestpoints(v, mid + 1, r, k - leftLength);
    }
    double dist(vector<vector<int>> v, int i){
        return v[i][0]*v[i][0] + v[i][1]*v[i][1];
    }
    int partition(vector<vector<int> > &v, int l, int r){
        
        int pi = dist(v, l);
        int i = l+1;
        for(int j=l+1; j<=r; j++){
            if(dist(v,j) <= pi){
                swap(v[i], v[j]);
                i++;
            }
        }
        return i-1;
    }
};
