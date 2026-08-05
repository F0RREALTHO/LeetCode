class Solution {
public:
    // int f(vector<vector<int>>& tri, vector<vector<int>>& dp,int i,int j,int n){
    //     if(i==n-1) return tri[i][j];
    //     if(dp[i][j]!=1e5) return dp[i][j];

    //     // int down = tri[i][j] + f(tri,dp,i+1,j,n);
    //     // int right = tri[i][j] + f(tri,dp,i+1,j+1,n);
    //     return dp[i][j] = min(tri[i][j] + f(tri,dp,i+1,j,n),tri[i][j] + f(tri,dp,i+1,j+1,n));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,1e5));
        
        // for(int j=0; j<n; j++){
        //     dp[n-1][j] = triangle[n-1][j];
        // }
        // for(int i = n-2; i>=0; i--){
        //     for(int j=0; j<=i;j++){
        //         int down = triangle[i][j]+dp[i+1][j];
        //         int left = triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j] = min(down, left);
        //     }
        // }
        // return dp[0][0];
        // return f(triangle,dp,0,0,n);

        vector<int> dp(n,0);
        for(int i =0; i<n;i++) dp[i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=0; j<=i; j++){
                temp[j] = min(triangle[i][j] + dp[j],triangle[i][j] + dp[j+1]);
            }
            dp= temp;
        }
        return dp[0];
    }
};