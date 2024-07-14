
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        ListNode* temp = head;
        unordered_set<int> st;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        

        for(int &i: nums)st.insert(i);
        ListNode* prev = newhead;
        while(temp){
            if(st.find(temp->val) != st.end()){
               
                    prev->next =  temp->next;
                    delete temp;
                    temp = prev->next;
                
            }else{
                prev = temp;
                temp = temp->next;
            }

        }

        
        return newhead->next;
        
        
    
    }
};