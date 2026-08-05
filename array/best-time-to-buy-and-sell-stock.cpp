class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    int maxProfit(vector<int>& a) {
        ll buy = a[0], best = 0, n = a.size();
        rep(i,1,n){
            if(a[i]<buy){
                buy = a[i];
            } else if(a[i]-buy>best){
                best = a[i]-buy;
            }
        }
        return best;
    }
};