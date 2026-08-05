class Solution {
public:
    int alternateDigitSum(int n) {
        int s = 0,d=1,p=1;
        while(n/d>=10) d*=10;
        while(d>0){
            s+=p*(n/d);
            p*=-1;
            n%=d;
            d/=10;
        }
        return s;
    }
};