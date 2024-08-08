
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> mat(n, vector<int>(m, -1));
        if (!head) return mat;

        ListNode* temp = head;
        int top = 0, bottom = n-1, left = 0, right = m -1;
        while(temp && top <= bottom && left <= right){

            for(int col = left; col <= right; col++){
                if(!temp){
                    return mat;
                }
                mat[top][col] = temp->val;
                temp = temp->next;
            }
            top++;

            
            
            for(int row = top; row <=bottom; row++){
                if(!temp){
                    return mat;
                }
                mat[row][right] = temp->val;

                temp = temp->next;
            }

            right--;
           
            for(int col = right; col >= left; col--){
                if(!temp){
                    return mat;
                }
                mat[bottom][col] = temp->val;

                temp = temp->next;
            }
            bottom--;
            
            
            for(int row = bottom; row >= top; row--){
                if(!temp){
                    return mat;
                }
                mat[row][left] = temp->val;
                temp = temp->next;
            }
            left++;
           

        }

        return mat;
    }
};