class Solution {

    bool valid(int &i, int &j, int &r, int &c){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        vector<vector<int>>  ans;

        int step = 1, dx = 0, dy = 1, temp;

        // int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxSize = rows * cols;
        while(ans.size() < maxSize ){

            for(int pair = 0; pair<2; pair++){
                for(int j = 0; j<step; j++){
                    if(valid(rs, cs, rows, cols)){
                        ans.push_back({rs, cs});
                    }

                    rs += dx;
                    cs += dy;
                }
                temp = dx;
                dx = dy;
                dy = -temp;
            }

            ++step;
        }







        return ans;


    }
};