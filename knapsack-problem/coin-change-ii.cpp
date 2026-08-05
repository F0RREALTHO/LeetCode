class Solution {
public:
    // int f(vector<vector<int>>& dp, vector<int>& coins, int amount, int i, int n){
    //     if(amount ==0) return 1;
    //     if(amount<0) return 0;
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][amount]!=-1) return dp[i][amount];
    //     int x = f(dp,coins,amount-coins[i],i,n);
    //     int y  = f(dp,coins,amount,i+1,n);
    //     return dp[i][amount] = x+y;

    // }
    int change(int amount, vector<int>& coins) {
        unsigned long long n = coins.size();
        // vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,-1));
        // // int ans= f(dp,coins,amount,0,n);
        // // return ans;
        // for(unsigned long long i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        // for(unsigned long long amt =1; amt<=amount; amt++){
        //     if(amt%coins[0]==0) dp[0][amt] = 1;
        //     else dp[0][amt] = 0;
        // }

        // for(unsigned long long i =1;i <n; i++){
        //     for(unsigned long long amt = 1; amt<=amount; amt++){
        //         unsigned long long x = dp[i-1][amt];
        //         unsigned long long y = 0;
        //         if(amt>=coins[i]){
        //             y = dp[i][amt-coins[i]];
        //         }
        //         dp[i][amt] = x+y;
        //     }
        // }
        // return dp[n-1][amount];

        vector<unsigned long long> dp(amount+1,-1);
        dp[0]=1;
        for(int amt =1; amt<=amount; amt++){
            if(amt%coins[0]==0) dp[amt] = 1;
            else dp[amt] =0;
        }
        for(int i=1;i<n;i++){
            vector<unsigned long long> temp(amount+1,-1);
            temp[0]=1;
            for(int amt =1;amt<=amount;amt++){
                unsigned long long x = dp[amt];
                unsigned long long y= 0;
                if(amt>=coins[i]){
                    y = temp[amt-coins[i]];
                }
                temp[amt] = x+y;
            }
            dp = temp;
        }
        return dp[amount];
    }
};