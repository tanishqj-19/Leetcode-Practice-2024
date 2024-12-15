class Solution {
public:

    double calculateGain(int pass,int stud){
        return (double)(pass+1)/(stud+1) - (double)(pass)/stud;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
        int i=0;
        for(auto it:classes){
            pq.push({calculateGain(it[0],it[1]),i});i++;
        }
        while(es--){
            auto [max_gain,idx]= pq.top(); pq.pop();
            classes[idx][0]+=1 ; classes[idx][1]+=1;
            pq.push({calculateGain(classes[idx][0],classes[idx][1]),idx});
        }
        double total=0.0;
        for(auto it:classes){
            total+=(double)it[0]/it[1];
        }
        return total/classes.size();
    }
    
};