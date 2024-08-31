class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        // size of the array

        int n = grades.size();

        // sort the array

        sort(grades.begin(), grades.end());


        int prevSum = 0, prevStudents = 0;
        int currSum = 0, currStudents = 0, groups = 0;
        int i = 0;
        for(; i<n; i++){
            
            
            currSum += grades[i];
            currStudents++;
            

            if(currSum > prevSum && currStudents > prevStudents ){
                prevSum = currSum;
                prevStudents = currStudents;
                groups++;
                currSum = currStudents = 0;
            }
            
        }


        return groups;
    }
};