
class Solution {

    ListNode* reverse(ListNode* head){
        auto curr = head;
        ListNode* prev = NULL, *next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }

        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;

        string num1 = "";
        while(temp){
            num1 += (to_string(temp->val));
            temp = temp->next;
        }

        string num2 = num1;

        
        int  i = num1.size()-1;
        int carry = 0;
        ListNode* newhead = new ListNode(0);

         temp = newhead;
        while(i >= 0){
            int x = carry;
            
            x += num1[i] - '0';
            x += num2[i] - '0';
    
            
            i--;

            carry = x / 10;
            temp->next = new ListNode(x % 10);
            temp = temp->next;
            
            
        }
        if(carry != 0){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        return reverse(newhead->next);
    }
};