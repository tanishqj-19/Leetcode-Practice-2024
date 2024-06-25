
class Solution {

    unordered_map<TreeNode*, TreeNode*> parentof;

    void solve(TreeNode* root){
        if(!root)
            return;
        
        if(root->left)
            parentof[root->left] = root;
        if(root->right)
            parentof[root->right] = root;
        
        solve(root->left);
        solve(root->right);
        return;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        solve(root);

        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
    
        while(!q.empty()){
            root = q.front();q.pop();

            if(parentof.find(root) != parentof.end()){
                if(parentof[parentof[root]]){
                    int val = parentof[parentof[root]]->val;
                    if(val % 2 == 0)
                        sum += root->val;
                }
            }

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }

        return sum;
    }
};