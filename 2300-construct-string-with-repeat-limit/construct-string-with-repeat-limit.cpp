class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> mp;

        for(char &c: s) mp[c]++;

        string ans = "";

        priority_queue<pair<char, int>> pq;

        for(auto &x: mp) pq.push({x.first,x.second});
        
        while(!pq.empty()){
            auto [c, cnt] = pq.top(); pq.pop();
            
            int used = min(repeatLimit, cnt);
            ans.append( used, c);
            cnt -= used;

            if(cnt > 0){
                if(pq.empty()) break;
                
                auto [nextC, nextCnt] = pq.top(); pq.pop();
                ans += nextC;
                nextCnt--;

                if(nextCnt > 0) pq.push({nextC, nextCnt});
                pq.push({c, cnt});
            }
        }


        return ans;

        
    }
};