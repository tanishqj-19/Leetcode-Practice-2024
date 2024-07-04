class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = new ListNode(0), *dummy = newhead;
        ListNode* temp = head;
        int sum = 0;
        while(temp){
            sum += temp->val;
            if(temp->val == 0 && sum != 0){
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                sum = 0;
            }
            temp = temp->next;
        }

        return newhead->next;
    }
};