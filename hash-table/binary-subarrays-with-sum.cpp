class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    int slidingWindowAtMost(vector<int>& nums, int goal) {
        ll l = 0;
        ll n = nums.size();
        ll sum = 0;
        ll ans = 0;
        if(goal<0) return 0;
        rep(r,0,n){
            sum+= nums[r];
            while(sum>goal){
                sum= sum - nums[l];
                l=l+1;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
};