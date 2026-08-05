class Solution {
public:

    long long const MOD = 1e9+7;

   long long f(long long a, long long b){
        long long ans = 1;
        while(b>0){
            if(b&1)
            ans = (ans*a)%MOD;
            a = (a*a)%MOD;
            b>>=1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        return (f(5,(n+1)/2) * f(4,n/2))%MOD;
    }
};