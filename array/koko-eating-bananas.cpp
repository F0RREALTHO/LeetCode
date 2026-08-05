class Solution {
public:
    #define ll long long

    ll calc(const vector<int>& piles, ll mid) {
        ll hr = 0;
        for (ll bananas : piles) {
            hr += (bananas + mid - 1) / mid; 
        }
        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 1;
        ll high = *max_element(piles.begin(), piles.end()); 
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll hr = calc(piles, mid);
            
            if (hr <= h) {
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
};
