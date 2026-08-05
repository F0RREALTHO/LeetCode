class Solution {
public:
    #define ll long long
    #define rep(i,j,k) for(ll i=j;i<k;i++)
    #define rrep(i,j,k) for(ll i=j;i>=k;i--)
    #define endl '\n'
    int longestOnes(vector<int>& nums, int k) {
        ll zero = 0;
        ll maxlen = 0;
        ll n = nums.size();
        ll l =0;
        rep(r,0,n){
            if(nums[r]==0) zero++;
            if(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            maxlen =max(maxlen,r-l+1);
        }
        return maxlen;
    }
};