class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        
        int size = 1 << n;

        if(k < size/2){
            return findKthBit(n-1, k);
        }else if(k == size / 2){
            return '1';
        }else{
            char temp = findKthBit(n-1, size - k);

            return (temp == '0') ? '1' : '0';


        }
    }
};