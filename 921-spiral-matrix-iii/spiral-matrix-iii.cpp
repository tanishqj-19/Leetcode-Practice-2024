class Solution {

    bool valid(int &i, int &j, int &r, int &c){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        vector<vector<int>>  ans;

        int step = 1, d = 0;

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxSize = rows * cols;
        while(ans.size() < maxSize ){

            for(int pair = 0; pair<2; pair++){
                for(int j = 0; j<step; j++){
                    if(valid(rs, cs, rows, cols)){
                        ans.push_back({rs, cs});
                    }

                    rs += dir[d][0];
                    cs += dir[d][1];
                }
                d  = (d + 1) % 4;
            }

            ++step;
        }







        return ans;


    }
};