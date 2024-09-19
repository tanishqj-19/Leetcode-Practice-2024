class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char &c: tasks) freq[c - 'A']++;

        priority_queue<int> pq;

        for(int &i: freq){
            if(i > 0)
                pq.push(i);
        }


        int least = 0;
        int cycle = n + 1;
        while(!pq.empty()){
            vector<int> curr;
            int i = 0;

            for(; i < cycle && !pq.empty(); i++){
                curr.push_back(pq.top()); pq.pop();
            }

            for(int j = 0; j<curr.size(); j++){
                if(--curr[j] > 0)
                    pq.push(curr[j]);
            }

            if(!pq.empty())
                least += cycle;
            else
                least += i;

            


        }

        return least;


         
    }
};