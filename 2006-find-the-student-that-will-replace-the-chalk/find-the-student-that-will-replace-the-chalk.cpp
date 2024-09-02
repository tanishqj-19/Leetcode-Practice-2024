#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int  i = 0;
        int sum = 0;
        for(int &x: chalk){
            sum = (sum +  x);
            if(sum > k)
                break;
        }
        k = k % sum;

        while(chalk[i] <= k){
            k -= chalk[i++];
        }
        

        return i;
    }
};