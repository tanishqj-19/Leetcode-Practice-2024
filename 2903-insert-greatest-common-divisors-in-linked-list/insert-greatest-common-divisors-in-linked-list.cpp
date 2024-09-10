class Solution {
    int gcd(int a, int b){

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)
            return head;
        
        ListNode* first = head;

        while(first->next){
            int val = gcd(first->val, first->next->val);

            ListNode* temp = first->next;
            first->next = new ListNode(val);
            first->next->next = temp;
            first = temp;
        }

        return head;
    }
};