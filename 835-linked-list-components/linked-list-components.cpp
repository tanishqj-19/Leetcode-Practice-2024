
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp = head;

        int component = 0;
        unordered_set<int> vis;
        for(int &i: nums) vis.insert(i);

        while(temp){
            if(vis.find(temp->val) != vis.end()){
                component++;
                while(temp && vis.find(temp->val) != vis.end())
                    temp = temp->next;
            }else{
                temp = temp->next;

            }
        }

        return component;
    }
};