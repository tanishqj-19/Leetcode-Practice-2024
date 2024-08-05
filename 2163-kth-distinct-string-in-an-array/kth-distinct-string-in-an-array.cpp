class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();

        unordered_map<string, int > track;
        for(int i = 0; i<n;i++){
            track[arr[i]]++;
        }

        for(auto &x: arr){
            if(track[x] == 1 && --k == 0)
                return x;
        }

        return "";
    }
};