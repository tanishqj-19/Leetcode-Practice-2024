class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        int sz = original.size();

        if(m * n != sz) 
            return ans;

        for(int i = 0; i < sz;){
            vector<int> temp;

            for(int j = 0; j<n; j++){
                temp.push_back(original[i++]);
            }

            ans.push_back(temp);
            temp.clear();
        }


        return ans;

    }
};