class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        priority_queue<pair<int, char>>pq;

        if(a > 0)
            pq.push({a, 'a'}); 
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        

        while(!pq.empty()){
            auto [freq, ch] = pq.top(); pq.pop();
           
            if(ans.empty() || ans.back() != ch){
                if(freq > 1){
                    freq -= 2;
                    ans.append(2, ch);
                }else{
                    ans += ch;
                    freq--;
                }
                
                if(freq > 0)
                    pq.push({freq, ch});
            }else{
                if(pq.empty())
                    break;
                vector<pair<int, char>> temp;
                while(!pq.empty() && ans.back() == ch){
                    temp.push_back({freq, ch});
                    freq = pq.top().first, ch = pq.top().second;
                    pq.pop();
                }

                ans += ch;
                freq--;
                if(freq > 0)
                    pq.push({freq, ch});


                if(temp.size()){
                    for(auto &x: temp) pq.push(x);
                }
            }
        }
        return ans;
    }
};