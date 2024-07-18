
class Solution {
    unordered_set<TreeNode*> leafs;
    unordered_map<TreeNode*, TreeNode*> parentof;
    int cnt = 0;
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left && !root->right){
            leafs.insert(root);
            return;
        }else{
            if(root->left)
                parentof[root->left] = root;
            if(root->right)
                parentof[root->right] = root;
            dfs(root->left);
            dfs(root->right);


        }
    }
    unordered_map<TreeNode*, bool> vis;


    void traversal(TreeNode* root, int d, int &maxD, unordered_map<TreeNode*, bool> &tempVis){
        if(!root || d > maxD)
            return;
        if(leafs.count(root) > 0 && !vis[root] && !tempVis[root]){
            cnt++;
        }
        tempVis[root] = true;
        traversal(root->left, d + 1, maxD, tempVis);
        traversal(root->right, d + 1, maxD, tempVis);
        traversal(parentof[root], d + 1, maxD, tempVis);


        
    }
public:
    int countPairs(TreeNode* root, int distance) {
        parentof[root] = nullptr;
        dfs(root);
        for(auto &x: leafs){
            
            vis[x] = true;
            unordered_map<TreeNode*, bool> temp;
            traversal(x, 0, distance, temp);
            // leafs.erase(x);
        }

        return cnt;
    }
};