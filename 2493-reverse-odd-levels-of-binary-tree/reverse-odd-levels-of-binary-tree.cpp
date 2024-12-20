/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* leftBaccha, TreeNode* rightBaccha, int level){
        if(!leftBaccha)
            return;
        if(level % 2 == 0){
            auto temp = rightBaccha->val;
            rightBaccha->val = leftBaccha->val;
            leftBaccha->val = temp;
        }
        dfs(leftBaccha->left, rightBaccha->right, level + 1);
        dfs(leftBaccha->right, rightBaccha->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);

        return root;
    }
};