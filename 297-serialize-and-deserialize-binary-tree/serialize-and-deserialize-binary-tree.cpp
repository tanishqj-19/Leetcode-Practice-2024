
class Codec {
public:
    
    string serialize(TreeNode* root) {

        if(!root){
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
       
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root){
                s = s + to_string(root->val) + ",";
                q.push(root->left);
                q.push(root->right);
            }else{
                s += "#,";
            }
        }

        
        return s;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        stringstream ss(data);
        string node;
        getline(ss, node, ',');

        TreeNode* root = new TreeNode(stoi(node));

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();

            getline(ss, node, ',');

            if(node != "#"){
                curr->left = new TreeNode(stoi(node));
                q.push(curr->left);
            }else{
                curr->left = NULL;
            }

            getline(ss, node, ',');

            if(node != "#"){
                curr->right = new TreeNode(stoi(node));
                q.push(curr->right);
            }else{
                curr->right = NULL;
            }
        }

        return root;

    }
};

