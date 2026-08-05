class Solution {
public:

#define ll long long

    bool tp(vector<int>& bloomDay, ll m, ll k, ll mid){
        ll n = bloomDay.size();        
        ll cnt = 0 , bouq = 0;
        for(ll i = 0; i<n; i++){
            if(bloomDay[i]<=mid){
                cnt++;
            } else {
               bouq += (cnt/k);
               cnt = 0;
            }
        }
        bouq += cnt/k;
        return m<=bouq;
    }

    int minDays(vector<int>& bloomDay, ll m, ll k) {
        ll n = bloomDay.size();
        if(n<m*k) return -1; 
        int high = INT_MIN;
        int low = INT_MAX;
        ll ans = 0;
        for(ll i =0; i<n; i++){
            high = max(high,bloomDay[i]);
            low = min(low,bloomDay[i]);
        }

        while(low<=high){
            ll mid = (low+high)/2;
            if(tp(bloomDay,m,k,mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};