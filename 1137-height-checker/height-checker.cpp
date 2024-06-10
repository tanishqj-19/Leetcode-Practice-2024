class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> x  = heights;

        sort(x.begin(), x.end());
        int c = 0;

        for(int i = 0; i<x.size(); i++){
            if(x[i] != heights[i]) c++;
        }

        return c;
    }
};