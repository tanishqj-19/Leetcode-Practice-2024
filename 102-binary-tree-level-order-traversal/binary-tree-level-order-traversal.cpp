
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();

            while(sz-- > 0){
                root = q.front(); q.pop();
                temp.push_back(root->val);

                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }

            ans.push_back(temp);
        }

        return ans;

    }

};