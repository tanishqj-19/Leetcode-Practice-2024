
class Solution {


    
    
    TreeNode* lca(TreeNode* root, int &x, int &y){
        if(!root)
            return root;
        if(root->val == x || root->val == y){
            return root;
        }

        TreeNode* left = lca(root->left, x, y);
        TreeNode* right = lca(root->right, x, y);

        if(left && right)
            return root;
        if(left)
            return left;
        return right;
    }
    bool find(TreeNode* src, int &val, string &s){
        if(!src)
            return false;
        
        
        if(src->val == val)
            return true;
        
        
        s.push_back('L');
        if(find(src->left, val, s))
            return true;
        s.pop_back();

        s.push_back('R');

        if(find(src->right, val, s))
            return true;
        s.pop_back();

        return false;
    
    }
public:
    string getDirections(TreeNode* root, int x, int y) {

        TreeNode* l = lca(root, x, y);

        string lca_to_src = "", lca_to_end = "";
        find(l, x, lca_to_src);
        find(l, y, lca_to_end);

        for(auto &ch: lca_to_src) ch = 'U';

        return lca_to_src + lca_to_end;


    }
};