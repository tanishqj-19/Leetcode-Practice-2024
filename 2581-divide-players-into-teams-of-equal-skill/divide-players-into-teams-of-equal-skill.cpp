#define ll long long

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        int k = accumulate(skill.begin(), skill.end(), 0) / (n/2);
        ll sum = 0;

        int cnt = 0;

        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++){
            
            
            if(mp.find(k - skill[i]) != mp.end()){
                cnt++;
                mp[k-skill[i]]--;
                
                if(mp[k-skill[i]] <= 0)
                    mp.erase(k-skill[i]);
                sum = (sum + (ll) skill[i] * (k - skill[i]));
                
            }else{
                mp[skill[i]]++;
            }
            
        }

        return cnt >= n/2 ? sum : -1;
    }
};