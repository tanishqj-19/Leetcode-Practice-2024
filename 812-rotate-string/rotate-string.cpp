class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();

        if(n != m)
            return false;
        if(n == 0)
            return true;

        string check = s + s;

        return check.find(goal) != string::npos;
    }
};