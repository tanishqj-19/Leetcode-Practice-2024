class Solution {
    int gcd(int a, int b){

        if (a == b)
            return a;
        if(a > b)
            return gcd(a - b, b);

        return gcd(a, b-a);
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