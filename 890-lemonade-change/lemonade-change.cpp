class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        

        int five = 0, ten = 0;


        for(int &i: bills){
            if(i == 5){
                five++;
            }else if(i == 10){
                ten++;
                if(five <= 0)
                    return false;
                five--;
            }else{
                
                if(ten > 0 && five > 0){
                    five--;
                    ten--;
                }else if(five >= 3){
                    five -= 3;
                }else
                    return false;
            }
        }

        return true;

    }
};