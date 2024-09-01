class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        int sz = original.size();

        if(m * n != sz) 
            return {};

        for(int i = 0; i < sz;){
            vector<int> temp;

            int j = 0;
            while(j < n){
                temp.push_back(original[i++]);
                j++;
            }

            if(!temp.empty())
                ans.push_back(temp);
        }


        return ans;

    }
};