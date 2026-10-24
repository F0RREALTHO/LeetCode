class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int k = sum;
        for(int i =0; i<num;i++){
            if(sum<10) {
                ans+=(sum+'0');
                sum=0;
            }
            else{
                ans+='9';
                sum-=9;
            }
        }
        int s = 0;
        for(int i=0; i<ans.size();i++){
            s+=(ans[i]-'0');
        }
        if(s!=k) ans = "";
        return ans;
    }
};