class Solution {
public:
    #define all(a) (a).begin(),(a).end()
    #define ll long long
    
bool tp(vector<int>& a, int k, int mid){
    ll n = a.size();
    ll cnt = 1;
    ll last = a[0];    
    for(int i = 1; i<n; i++){
        if(last+a[i]<=mid){     
            last += a[i];
        } else {
            cnt++;
            last = a[i];
            if(cnt > k) return false; 
        }
    }
    return true; 
}
    
    int splitArray(vector<int>& nums, int k) {
        ll low = *max_element(all(nums));
        ll high = accumulate(all(nums), 0LL);
        ll ans = high;
        
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(tp(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};