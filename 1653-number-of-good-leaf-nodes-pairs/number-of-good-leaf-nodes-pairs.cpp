
class Solution {
    
    vector<int> dfs(TreeNode* root, int distance, int &count){
        if(!root)
            return {};

        if(!root->left && !root->right){
            return {1};
        }
        vector<int> left = dfs(root->left, distance, count);
        vector<int> right = dfs(root->right, distance, count);

        for(int &i: left){
            for(int &j: right){
                if(i + j <= distance)
                    count++;
            }
        }

        vector<int> currD;
        for(int &i: left){
            if(i + 1 <= distance)
                currD.push_back(i + 1);
        }

        for(int &j: right){
            if(j + 1 <= distance)
                currD.push_back(j + 1);
        }

        return currD;


    }


    
public:
    int countPairs(TreeNode* root, int distance) {
        
        int count = 0;

        dfs(root, distance, count);
        return count;
    }
};