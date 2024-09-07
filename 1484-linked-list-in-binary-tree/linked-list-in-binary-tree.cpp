class Solution {
    vector<int> list;

    bool solve(TreeNode* root){
        if(!root)
            return false;
        
        if(dfs(root, 0))
            return true;
        return solve(root->left) || solve(root->right);
    }

    bool dfs(TreeNode* root, int idx){
        if(idx == list.size())
            return true;
        if(!root || root->val != list[idx])
            return false;
        
        
        return dfs(root->left, idx + 1) || dfs(root->right, idx + 1);

    }

    

public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        while(head){
            list.push_back(head->val);
            head = head->next;
        }

        return solve(root);



    }
};