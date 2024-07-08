class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        for(int i = 1; i<=n; i++) q.push(i);

        while(q.size() > 1){
            int x = 1;

            while(x < k){
                int back = q.front(); q.pop();
                q.push(back);
                x++;
            }
            q.pop();
        }

        return q.front();
    }

};