class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq(gifts.begin(), gifts.end());


        while(k > 0){
            double top = pq.top(); pq.pop();

            long long toAdd = floor(sqrt(top));

            pq.push(toAdd);
            k--;
        }

        long long total = 0;

        while(!pq.empty()) {
            total += pq.top(); pq.pop();
        }

        return total;
    }
};