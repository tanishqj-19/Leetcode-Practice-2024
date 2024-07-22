
class Solution {

    void dfs(TreeNode* root, int r, int c, map<int, map<int, multiset<int>>> & mp){

        if(root){
            mp[r][c].insert(root->val);
            dfs(root->left, r-1, c + 1, mp);
            dfs(root->right, r + 1, c + 1, mp);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        dfs(root, 0, 0, nodes);

        vector<vector<int>> ans;

        for(auto &x: nodes){
            vector<int> cols;
            for(auto &n: x.second){
                cols.insert(cols.end(), n.second.begin(), n.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
    }
};