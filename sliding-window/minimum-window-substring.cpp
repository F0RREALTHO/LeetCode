class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    string minWindow(string s, string t) {
        ll l = 0;
        ll n = s.size();
        ll m = t.size();
        string ans = "";
        ll stridx = -1;
        ll maxlen = LLONG_MAX;
        ll cnt = 0;
        map<char,ll> mp;
        rep(i,0,m){
            mp[t[i]]++;
        }
        rep(r,0,n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1<maxlen){
                    maxlen = r-l+1;
                    stridx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
        }
    return stridx ==-1?"":s.substr(stridx,maxlen);
    }
};