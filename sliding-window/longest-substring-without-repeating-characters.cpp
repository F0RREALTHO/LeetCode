class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    #define rrep(i,j,k) for(ll i=j;i>=k;i--)
    #define endl '\n'
    int lengthOfLongestSubstring(string s) {
        ll n = s.size();
        vector<ll> hash(256,-1);
        ll ans = 0;
        ll l = 0;
        rep(r,0,n){
            if(hash[s[r]]!=-1){
                l = max(l,hash[s[r]]+1);
            }
            hash[s[r]]=r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};