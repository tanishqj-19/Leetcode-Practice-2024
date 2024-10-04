#define ll long long

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        ll sum = 0;
        vector<int> freq(1001, 0);

        for(auto &i: skill){
            sum += i;
            freq[i]++;
        }


        if(sum % (n/2) != 0)
            return -1;
        int k = sum / (n/2), need;

        ll totalAns = 0;

        for(int i = 0; i<n; i++){
            need = k - skill[i];

            if(freq[need] == 0){
                return -1;
            }else{
                freq[need]--;
                totalAns += (ll) (need * skill[i]);
            }
        }

        return totalAns / 2;

        

    
    }
};