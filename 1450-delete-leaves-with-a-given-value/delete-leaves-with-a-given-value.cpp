
class Solution {

    TreeNode*solve(TreeNode* root, int x){
        
        if(!root)
            return nullptr;
        

        root->left = solve(root->left, x);
        root->right = solve(root->right, x);

        if(!root->left && !root->right && root->val == x){
            root = NULL;
            
        }
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};