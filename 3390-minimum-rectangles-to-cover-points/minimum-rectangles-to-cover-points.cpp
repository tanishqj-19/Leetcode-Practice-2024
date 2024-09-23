class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());

        int n = points.size();

        int c = 1, last = points[0][0];
        for(int i=1; i<n; i++){
            if(points[i][0] - last <= w) continue;
           
            c++;
            last = points[i][0];
            
        }

        return c;
    }
};