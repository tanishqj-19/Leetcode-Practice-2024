
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int lv = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> parent;
            vector<int> temp;
            while(n-->0){
                TreeNode* curr = q.front(); q.pop();

                if(lv %  2 == 0){
                    parent.push_back(curr);
                }

                if(curr->left){
                     temp.push_back(curr->left->val);
                    q.push(curr->left);
                }

                if(curr->right){
                     temp.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }

            if(!temp.empty())
                for(auto node: parent){
                    node->left->val = temp.back(); temp.pop_back();
                    node->right->val = temp.back(); temp.pop_back();
                }  

            lv++;
        }

        return root;
    }
};