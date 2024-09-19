
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = NULL;

        q.push(root);

        while(!q.empty()){
            root = q.front(); q.pop();

            if(root->val == start)
                target = root;
            if(root->left){
                parent[root->left] = root;
                q.push(root->left);
            }
            if(root->right){
                parent[root->right] = root;
                q.push(root->right);
            }
        }
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int time = 0;

        while(!q.empty()){
            int n = q.size();
            int i =0;
            bool flag = false;
            while(i++ < n){
                root = q.front(); q.pop();

                if(root->left && !visited[root->left]){
                    visited[root->left] = true;
                    flag = true;
                    q.push(root->left);
                }
                if(root->right && !visited[root->right]){
                    visited[root->right] = true;
                    flag = true;
                    q.push(root->right);
                }
                if(parent[root] && !visited[parent[root]]){
                    visited[parent[root]] = true;
                    flag = true;
                    q.push(parent[root]);
                }
            }

            if(flag)
                time++;
        }


        return time;


    }
};