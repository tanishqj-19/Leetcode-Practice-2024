#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int  i = 0, n = chalk.size();
        ll sum = 0;
        for(int &x: chalk){
            sum = (sum + (ll) x);
            if(sum > k)
                break;
        }
        ll remain = k % sum;

        while(chalk[i] <= remain){
            remain -= chalk[i++];
        }
        

        return i;
    }
};