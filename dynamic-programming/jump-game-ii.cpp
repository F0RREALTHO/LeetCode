class Solution {
public:
    int f(vector<int>& nums ,int n,int idx, vector<int>& dp){
        if(idx>=n-1) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int mini = INT_MAX;
        for(int i =idx+1;i<=idx+nums[idx] && i<n;i++){
            int x = f(nums,n,i,dp);

            if(x!=INT_MAX){
                mini=min(mini,1+x);
            }
        }
        return dp[idx]=mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,n,0,dp);
    }
};