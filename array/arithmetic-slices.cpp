class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size(), cnt = 0, len = 0;
        if(nums.size()<3) return 0;
        rep(i,2,n){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                len++;
                cnt += len;
            } else {
                len = 0;
            }
        }
        return cnt;
    }
};