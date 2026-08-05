class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    int odd(vector<int>& nums, int k) {
        ll l = 0;
        ll n = nums.size();
        ll ans = 0;
        ll odd = 0;
        rep(r,0,n){
            if(nums[r]%2!=0) odd++;
            while(odd>k){
                if(nums[l]%2!=0){
                    odd--;
                }
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        return odd(nums,k) - odd(nums,k-1);
    }    
};