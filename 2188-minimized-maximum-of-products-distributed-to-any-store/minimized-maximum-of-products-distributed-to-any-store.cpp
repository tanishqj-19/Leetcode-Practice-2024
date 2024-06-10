class Solution {

    bool myProduct(vector<int> &quantities, int d, int k){
        int total = 0, c =0;
        int i  = 0, n = quantities.size();
        while(i < n){
            
            total += (quantities[i] + d - 1) / d;
            i++;
        }  

        if(total > k)
            return true;
        return false; 
    }
public:
    int minimizedMaximum(int k, vector<int>& quantities) {
        int low = 1, high = 0, n = quantities.size();

        for(int &i: quantities) high = max(i, high);
        int ans = 0;

        while(low <= high){
            int mid  = (low + high) / 2;

            if(myProduct(quantities, mid, k)){
                low = mid + 1;
                
            }else
                high = mid - 1;

            
        }

        return low;

        return ans;
    }
};

