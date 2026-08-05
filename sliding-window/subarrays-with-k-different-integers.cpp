class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    int hehe(vector<int>& nums, int k) {
        ll l = 0;
        ll ans = 0;
        ll n = nums.size();
        unordered_map<ll,ll> mp;
        rep(r,0,n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return hehe(nums,k) - hehe(nums,k-1);
    }    
};