class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& arr) {
        // vector<vector<int>> grid(n, vector<int>(n));

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         grid[i][j] = (i *n) + j;
        //     }
        // }

        int r = 0, c = 0;

        for(int i =0; i<arr.size(); i++){
            if(arr[i] == "RIGHT"){
                c++;
            }else if(arr[i] == "LEFT")
                c--;
            else if(arr[i] == "UP")
                r--;
            else
                r++;
        }

        return r * n + c;
    }
};