class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    #define rrep(i,j,k) for(ll i=j;i>=k;i--)
    #define endl '\n'
    #define min3(a,b,c) min(a,min(b,c))
    int numberOfSubstrings(string s) {
        // ll l = 0;
        // ll n = s.size();
        ll c = 0;
        // map<char,ll> mp;
        // rep(r,0,n){
        //     mp[s[r]]++;
        //     while(mp.size()==3){
        //         c+=n-r;
        //         mp[s[l]]--;
        //         if(mp[s[l]]==0) mp.erase(s[l]);
        //         l++;
        //     }
        // }
        // return c;

        vector<ll> seen(3,-1);
        ll n = s.size();
        rep(i,0,n){
           seen[s[i]-'a']=i;
           if(seen[0]!=-1 && seen[1]!=-1 && seen[2]!=-1){
            c+=min3(seen[0],seen[1],seen[2])+1;
           }
        }
        return c;
    }
};