#define ptl pair<TreeNode*, ListNode*>
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        stack<ptl> st;

        st.push({root, head});


        while(!st.empty()){
            auto [node, list] = st.top(); st.pop();

            if(matching(node, list))
                return true;
            
            if(node->left)
                st.push({node->left, list});
            if(node->right)
                st.push({node->right, list});
        }

        return false;
    }
private:
    bool matching(TreeNode* root, ListNode* head){
        while(root && head){
            if(root->val != head->val)
                return false;
            head = head->next;

            if(head){
                if(root->left && matching(root->left, head))
                    root = root->left;
                else
                    root = root->right;
            }
        }

        return head == NULL;
    }
};