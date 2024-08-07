class Solution {

    unordered_map<int,string> d = {
                    {0, "Zero"},
                    {1, "One"},
                    {2, "Two"},
                    {3, "Three"},
                    {4, "Four"},
                    {5, "Five"},
                    {6, "Six"},
                    {7, "Seven"},
                    {8, "Eight"},
                    {9, "Nine"},
                    {10, "Ten"},
                    {11, "Eleven"},
                    {12, "Twelve"},
                    {13, "Thirteen"},
                    {14, "Fourteen"},
                    {15, "Fifteen"},
                    {16, "Sixteen"},
                    {17, "Seventeen"},
                    {18, "Eighteen"},
                    {19, "Nineteen"},
                    {20, "Twenty"},
                    {30, "Thirty"},
                    {40, "Forty"},
                    {50, "Fifty"},
                    {60, "Sixty"},
                    {70, "Seventy"},
                    {80, "Eighty"},
                    {90, "Ninety"},
                    {100, "Hundred"},
                    {1000, "Thousand"},
                    {1000000, "Million"},
                    {1000000000, "Billion"}
                };
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        return solveEnglish(num);
        
    }
private:
    string solveEnglish(int num){
        if(num == 0)
            return "";
        else if(num < 20)
            return d[num];
        else if(num < 100){
            return d[(num / 10) * 10] + (num % 10 ? " " + solveEnglish(num % 10) : "");
        }else if(num < 1000){
            return solveEnglish(num / 100) + " " + d[100] + (num % 100 ? " " + solveEnglish(num % 100) : "");
        }else if(num < 1000000){
            return solveEnglish(num / 1000) + " " + d[1000] + (num % 1000 ? " " + solveEnglish(num % 1000) : "");
        }else if(num < 1000000000){
            return solveEnglish(num / 1000000) + " " + d[1000000] + (num % 1000000 ? " " + 
                    solveEnglish(num % 1000000) : "");
        }

        return solveEnglish(num / 1000000000) + " " + d[1000000000] + (num % 1000000000 ? " " + 
                    solveEnglish(num % 1000000000) : "");
    }
};