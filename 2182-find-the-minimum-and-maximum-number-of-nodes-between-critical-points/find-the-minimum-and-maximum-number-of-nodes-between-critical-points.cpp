
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        ListNode* temp  = head, *prev = nullptr;
        int c = 0;
        while(temp->next){
            c++;
            if(prev && (temp->val > prev->val && temp->val > temp->next->val)){
                critical.push_back(c);
            }
            if(prev && temp->val < prev->val && temp->val < temp->next->val)
                critical.push_back(c);
            prev = temp;
            temp =  temp->next;
        }

        if(critical.size() <= 1)
            return {-1,-1};
        
        int maxi = critical.back() - critical[0], mini = 1e9;
        for(int i = 0; i<critical.size() - 1; i++){
            mini = min(mini, critical[i+1] - critical[i]);
        }


        return {mini, maxi};
        


    }
};