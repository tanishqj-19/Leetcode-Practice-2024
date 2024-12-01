class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for(int i = 0; i<n; i ++){

            if(arr[i] == 0 && mp[0] > 1) return true;
            else if(arr[i] != 0 && mp.find(arr[i] * 2) != mp.end()){
                return true;
            }
        }

        return false;
    }
};