class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0)
            return true;
        
        for(int i = num/2; i<num; i++){
            string x = to_string(i);
            reverse(x.begin(), x.end());
            if(stoi(x) + i == num)
                return true;
        }

        return false;
    }
};