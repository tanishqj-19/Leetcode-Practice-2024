class node{
public:
    int val;
    int row;
    int col;
    node(int data, int i, int j){
        val = data;
        row = i;
        col = j;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*>, compare> minheap;

        int maxi = INT_MIN, mini = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            minheap.push(new node(nums[i][0], i, 0));
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }

        vector<int> ans(2);
        ans[0] = mini;
        ans[1] = maxi;

        while(minheap.size() > 0){
            node* top = minheap.top();
            minheap.pop();
            mini = top->val;
            
            if(maxi - mini < ans[1]- ans[0]){
                ans[1] = maxi;
                ans[0]= mini;
            }

            if(top->col + 1 < nums[top->row].size()){
                maxi = max(nums[top->row][top->col + 1], maxi);
                minheap.push(new node(nums[top->row][top->col + 1], top->row, top->col + 1));
            }else{
                break;
            }
        }

        return ans;
    }
};