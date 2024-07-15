class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,  TreeNode*> nodes;

        unordered_map<int, bool> child;

        for(auto &x: descriptions){
            
            if(nodes.find(x[0]) == nodes.end()){
                nodes[x[0]] = new TreeNode(x[0]);
            }
            if(nodes.find(x[1]) == nodes.end()){
                nodes[x[1]] = new TreeNode(x[1]);
            }

            if(x[2])
                nodes[x[0]]->left = nodes[x[1]];
            else
                nodes[x[0]]->right = nodes[x[1]];
            child[x[1]] = true;
        }


        TreeNode* root;

        for(auto &x: descriptions){
            if(!child[x[0]])
                root = nodes[x[0]];
        }

        return root;

    }
};