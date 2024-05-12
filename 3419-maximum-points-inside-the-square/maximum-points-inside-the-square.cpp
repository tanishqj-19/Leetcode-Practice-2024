class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char, int> mp;
        int second_min = 1e9;
        int n = points.size();
    
        for(int i = 0; i < n ; i++){
            int x = abs(points[i][0]), y = abs(points[i][1]);

            char c = s[i];
            int len = max(x, y);

            if(mp.find(c) == mp.end()){
                mp[c] = len;
            }else if(len < mp[c]){
                second_min = min(mp[c], second_min);
                mp[c] = len;

            }else{
                second_min = min(len, second_min);
            }
        }

        int count = 0;

        for(auto &x: mp){
            
            if(x.second < second_min) count++;
        }

        return count;
    }
};