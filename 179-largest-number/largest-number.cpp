class Solution {
    static bool cmp(string &a, string&b){
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        string large = "";

        int n = nums.size();
        vector<string> arr;
        for(int &i: nums) arr.push_back(to_string(i));

        sort(arr.begin(), arr.end(), cmp);

        for(auto &word : arr){
            large += word;
        }
        if(large[0] == '0')
            return "0";

        return large;


        




    }
};