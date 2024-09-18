class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n-1;

        while(low <= high){

            int mid = (low + high) / 2;
            int maxCol = 0;

            for(int i = 0; i<m; i++){
                if(mat[mid][i] > mat[mid][maxCol])
                    maxCol = i;
            }

            if((mid == 0 || mat[mid][maxCol] > mat[mid-1][maxCol]) && (mid == n-1 || mat[mid][maxCol] > mat[mid + 1][maxCol]))

                return {mid, maxCol};

            if(mid > 0 && mat[mid-1][maxCol] > mat[mid][maxCol])
                high = mid - 1;
            else
                low = mid + 1;
        }



        return {-1, -1};


    }
};