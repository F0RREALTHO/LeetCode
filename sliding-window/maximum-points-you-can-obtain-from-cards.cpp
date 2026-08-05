class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    #define rrep(i,j,k) for(ll i=j;i>=k;i--)
    #define endl '\n'
    int maxScore(vector<int>& cardPoints, int k) {
        ll rsum = 0;
        ll lsum = 0;
        rep(i,0,k) lsum += cardPoints[i];
        ll n = cardPoints.size();
        ll ans = lsum;
        rep(i,0,k){
            lsum -= cardPoints[k-1-i];
            rsum += cardPoints[n-i-1];
            ans = max(ans,lsum+rsum);
        }
        return ans;
    }
};