#define pici pair<int, pair<char, int>>

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> arr(n, vector<int>(4));

        for(int i = 0; i<n; i++){
            if(directions[i] == 'L')
                arr[i] = {positions[i], 0, healths[i], i};
            else
                arr[i] = {positions[i], 1, healths[i], i};
        }


        sort(arr.begin(), arr.end());

        vector<vector<int>> st;
       
        for(int i = 0; i<n; i++){
            if(arr[i][1] == 1){
                st.push_back(arr[i]);
                continue;
            }

            bool isRemoved = false;

            while(!st.empty() && st.back()[1] == 1 && st.back()[2] <= arr[i][2]){
                if(st.back()[2] == arr[i][2]){
                    isRemoved = true;
                    st.pop_back();
                    break;
                }
                arr[i][2]--;
                st.pop_back();
            }

            if(!isRemoved && !st.empty() && st.back()[1] == 1 && st.back()[2] > arr[i][2]){
                isRemoved = true;
                st.back()[2] -= 1;
            }

            if(!isRemoved)
                st.push_back(arr[i]);


            
        }

        sort(st.begin(), st.end(), [](vector<int> &a, vector<int> &b){
            return a[3] < b[3];
        });

        vector<int> ans;

        for(auto &i: st){
            ans.push_back(i[2]);
        }

        return ans;

    }

};