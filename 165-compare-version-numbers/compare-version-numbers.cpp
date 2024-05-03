class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;

        
        long long n1  = 0, n2  = 0;

        int sz1 = version1.size(), sz2 = version2.size();

        while(p1 < sz1 || p2 < sz2){

            while(p1 < sz1 && version1[p1] != '.'){
                n1 = (n1 * 10) + version1[p1] - '0';
                p1++;
            }

            while(p2 < sz2 && version2[p2] != '.'){
                n2 = (n2 * 10) + version2[p2] - '0';
                p2++;
            }


            if(n1 < n2)
                return -1;
            if(n1 > n2)
                return 1;
            
            n1 = n2 = 0;
            p1++;
            p2++;
        }

        return 0;
    }
};