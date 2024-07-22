class Solution {
    int n;
    int sz;

    map<vector<int>, int> dp;

    int shop(vector<int> &price, vector<int> & needs, vector<vector<int>>& special){

        if(dp.find(needs) != dp.end())
            return dp[needs];

        int offer = direct(price, needs);

        for(int idx = 0; idx < sz; idx++){
            vector<int> curr = special[idx];

            vector<int> temp;

            for(int j = 0; j<needs.size(); j++){

                if(needs[j] < curr[j]){
                    temp = {};
                    break;
                }
                temp.push_back(needs[j] - curr[j]);
            }

            if(!temp.empty())
                offer = min(offer, curr[curr.size() - 1] + shop(price, temp, special));

            // temp.clear();
// 

        }

        return dp[needs] =  offer;


    }

    int direct(vector<int> &price, vector<int> &needs){
        int total = 0;

        for(int i = 0; i<needs.size(); i++){
            total += (price[i] * needs[i]);
        }
        

        return total;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {


        n = price.size();
        sz = special.size();

        return shop(price, needs, special);


        
    }
};