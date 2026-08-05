class Solution {
public:
    #define all(a) (a).begin(),(a).end()
    #define ll long long
    int findKthPositive(vector<int>& arr, int k) {
        ll low = 1;
        ll high = arr.back() + k;  // Changed this
        
        while(low <= high){
            ll mid = low + (high-low)/2;
            ll idx = upper_bound(all(arr), mid) - arr.begin();
            ll he = mid - idx;
            
            if(he < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};