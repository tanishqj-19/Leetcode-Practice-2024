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


        int least = 0, cycle, task;
        while(!pq.empty()){
            vector<int> curr;
            cycle = n + 1;
            task = 0;
            while(cycle-- && !pq.empty()){
                if(pq.top() > 1)
                    curr.push_back(pq.top() - 1);
                pq.pop();
                task++;
            }
            
            for(auto &x:  curr)
                pq.push(x);
            

            if(!pq.empty())
                least += (n + 1);
            else
                least += task;

        }

        return least;


         
    }
};