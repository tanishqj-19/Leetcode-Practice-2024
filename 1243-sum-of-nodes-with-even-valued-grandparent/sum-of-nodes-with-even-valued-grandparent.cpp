
class Solution {
    
    int solve(TreeNode* root, int p, int gp){
        if(!root)
            return 0;
        
        
        int left = solve(root->left, root->val, p);
        int right = solve(root->right, root->val, p);
        if(gp % 2 == 0)
            return left + right + root->val;
        return left + right;
            
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, 1,1);
    }
};