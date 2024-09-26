class MyCalendar {
    vector<pair<int, int>> arr;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        

        for(auto &x: arr){
            if(x.first < end && start < x.second){
                return false;
            }
        }

        arr.push_back({start, end});
        return true;


    }
};
