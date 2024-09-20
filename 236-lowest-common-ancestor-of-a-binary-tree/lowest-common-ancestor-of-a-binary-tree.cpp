
class Solution {
    TreeNode* lowest(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q){
            return root;
        }

        auto left = lowest(root->left, p, q);
        auto right = lowest(root->right, p , q);

        if(left && right)
            return root;
        return !left? right : left;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowest(root, p, q);
    }
};