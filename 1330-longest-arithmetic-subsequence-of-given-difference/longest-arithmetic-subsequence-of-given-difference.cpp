class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        unordered_map<int, int> dp;
        int longest = 1;
        for(int i = 0;i<n; i++){
            dp[arr[i]] = 1 + dp[arr[i] - difference];
            longest = max(longest, dp[arr[i]]);
        }

        return longest;
    }
};