class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n+m,0);
        for(int i = n-1; i >= 0; i--){
            int x = num1[i]-'0';
            int car = 0;
            for(int j = m-1; j >= 0; j--){
                int y = num2[j]-'0';
                int z = x*y + car + ans[i+j+1];
                ans[i+j+1] = z%10;
                car = z/10;
            }
            ans[i] += car;
        }

        string res = "";
        for(int i = 0; i < ans.size(); i++){
            if(res == "" && ans[i] == 0) continue;
            res += char(ans[i]+'0');
        }

        return res;
    }
};