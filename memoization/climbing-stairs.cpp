class Solution {
public:
    // int f(int n,vector<int>& dp){
    //     if(n<=1) return 1;
    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n] = f(n-1,dp) + f(n-2,dp);
    // }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return f(n,dp);

        int prev1 = 1;
        int prev2 = 1;
        int cur;

        for(int i = 2; i<=n; i++){
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};