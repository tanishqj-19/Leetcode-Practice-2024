class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char &c: tasks) freq[c - 'A']++;

        sort(freq.begin(), freq.end());

        int maxi = freq[25] - 1;
        int task = tasks.size();

        int idle = maxi * n;

        for(int i = 24; i >= 0 && freq[i] > 0 ; i--){
            idle -= min(maxi, freq[i]);
        }
    
        return idle > 0 ? task + idle : task;


         
    }
};