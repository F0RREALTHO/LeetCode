class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> a(min(numRows,int(s.size())));

        int curRow = 0;
        bool down = true;

        for(char c:s){
            a[curRow]+=c;
            if(curRow==0){down = true;}
            else if(curRow==numRows-1) {down = false;}

            if(down){curRow++;}
            else curRow--;
        }

        string ans  = "";
        for(auto r:a) ans+=r;

        return ans;
    }
};