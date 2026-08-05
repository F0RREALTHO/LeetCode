class Solution {
public:
    // int f(vector<vector<int>>& dp, vector<int>& coins, int amount, int i, int n){
    //     if(amount ==0) return 0;
    //     if(amount<0) return 1e9;
    //     if(i==n){
    //         return 1e9;
    //     }
    //     if(dp[i][amount]!=-1) return dp[i][amount];
    //     int x = 1+ f(dp,coins,amount-coins[i],i,n);
    //     int y  = f(dp,coins,amount,i+1,n);
    //     return dp[i][amount] = min(x,y);

    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // for(int i=0; i<n;i++){
        //     dp[i][0] = 0;
        // }
        // for(int amt =1; amt<=amount;amt++){
        //     if(amt%coins[0]==0){
        //         dp[0][amt] = amt/coins[0];
        //     }else{ dp[0][amt] = 1e9;}
        // }
        // for(int i =1; i<n;i++){
        //     for(int amt =1; amt<=amount; amt++){
        //         int x = dp[i-1][amt];
        //         int y = 1e9;
        //         if(amt>=coins[i]){
        //             y = 1+ dp[i][amt-coins[i]];
        //         }
        //         dp[i][amt] = min(x,y);
        //     }

        // }
        // int ans= dp[n-1][amount];
        // return ans >= 1e9? -1:ans;
        vector<int> dp(amount+1,1e9);
        for(int amt=1; amt<=amount;amt++){
            if(amt%coins[0]==0) dp[amt] = amt/coins[0];
        }

        for(int i =0; i<n; i++){
            vector<int> temp(amount+1,1e9);
            temp[0]=0;
            for(int amt = 1; amt<=amount;amt++){
                int x = dp[amt];
                int y = 1e9;
                if(amt>=coins[i]){
                    y = 1+temp[amt-coins[i]];
                }
                temp[amt] = min(x,y);
            }
            dp = temp;
        }
        return dp[amount]>=1e9? -1:dp[amount];
    }
};