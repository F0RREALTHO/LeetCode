class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int n, int idx){
        if(idx>=n) return 0;  
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(nums[idx] + f(nums,dp,n,idx+2),f(nums,dp,n,idx+1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        
        // dp[0] = nums[0];
        // dp[1] = max(nums[1],nums[0]);
        if(n==0) return 0;
        if(n==1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[1],nums[0]);
        int cur;
        for(int i = 2; i<n; i++){
            cur = max(nums[i] + prev2,prev1);
            prev2 = prev1;
            prev1 = cur;
        }

        // return f(nums,dp,n,0);
        return prev1;
    }
};