class Solution {
    vector<int> list;

    bool solve(TreeNode* root, ListNode* head){
        if(!root)
            return false;
        
        if(dfs(root, head))
            return true;
        return solve(root->left, head) || solve(root->right, head);
    }

    bool dfs(TreeNode* root, ListNode* head){
        if(!head)
            return true;
        if(!root || root->val != head->val)
            return false;
        
        
        return dfs(root->left, head->next) || dfs(root->right, head->next);

    }

    

public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        

        return solve(root, head);



    }
};