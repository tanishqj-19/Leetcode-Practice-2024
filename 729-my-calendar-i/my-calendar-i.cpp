class MyCalendar {
    set<pair<int, int>> s;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto it = s.lower_bound({start,end});

        if(it != s.end() && it->first < end)
            return false;
        
        if(it != s.begin()){
            auto previous = prev(it);

            if(previous->second > start)
                return false;
        }

        s.insert({start, end});
        return true;


    }
};
