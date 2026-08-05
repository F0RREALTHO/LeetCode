class Solution {
public:
#define ll long long

    bool tp(vector<int>& nums , ll mid, ll thereshold){
        ll n = nums.size() , sum = 0;
        for(int i = 0; i<n; i++){
            sum += (nums[i]+mid-1)/mid;
        }
        return sum<=thereshold;
    }

    int smallestDivisor(vector<int>& nums, ll threshold) {
        ll n = nums.size();
        ll ans = 0;
        int high = INT_MIN , low = 1;
        for(ll i = 0; i<n ; i++){
            high = max(high,nums[i]);
            // low = min(low,nums[i]);
        }
        while(low<=high){
            ll mid = (low+high)/2;
            if(tp(nums,mid,threshold)){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};