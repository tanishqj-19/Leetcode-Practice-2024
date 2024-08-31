class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        // size of the array

        int n = grades.size();

        // sort the array

        // sort(grades.begin(), grades.end());

        

        int prevStudents = 0;
        int currStudents = 0, groups = 0;
        int i = 0;
        for(; i<n; i++){
            
            

            currStudents++;
            
            if( currStudents > prevStudents ){
                prevStudents = currStudents;
                groups++;
                 currStudents = 0;
            }
            
        }


        return groups;
    }
};


// 3 5 6 7 10 12 

// 1-3 , 2 [5,6], 3-[7, 10, 12] , 4- [x, y, z,]