class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int idx, int end){
        if(idx>=end) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(nums[idx]+f(nums,dp,idx+2,end), f(nums,dp,idx+1,end));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int a1 = f(nums,dp,0,n-1);
        fill(dp.begin(),dp.end(),-1);
        int a2 = f(nums,dp,1,n);
        return max(a1,a2);
    }
};