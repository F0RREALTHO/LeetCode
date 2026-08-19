class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int x = 0;
        bool st = false;
        for(int i =0; i<n; i++){
            if(s[i]==' ' &&!st) continue;
            if(s[i]=='-'&& !st){
                sign=-1;
                st=true;
            }
            else if(s[i]=='+'&&!st) st = true;
    
            else if(s[i]>='0' && s[i]<='9'){
                st = true;
                int dig = s[i]-'0';
                if(x>INT_MAX/10 || (x==INT_MAX/10 && dig>7)){
                    return sign==1 ? INT_MAX : INT_MIN;
                }
                x = x*10 + dig;
            }
            else break;
        }
        return sign*x;
    }
};