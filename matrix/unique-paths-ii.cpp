class Solution {
public:
    // int f(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
    //     if(i<0 || j<0) return 0;
    //     if(i==0 && j==0) return 1;

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int x = 0,y=0;
    //     if(i>0 && grid[i-1][j]!=1) x = f(grid,dp,i-1,j); 
    //     if(j>0 && grid[i][j-1]!=1) y= f(grid,dp,i,j-1);

    //     return dp[i][j] = x+y;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        // return f(obstacleGrid,dp,m-1,n-1);
        // dp[0][0]=1;
        // for(int i = 0; i<m; i++){
        //     for(int j =0; j<n; j++){
        //         if(obstacleGrid[i][j]==1) {
        //             dp[i][j] = 0;
        //             continue;
        //         }
        //         if(i==0 &&  j==0) continue;
        //         int up =0,lft = 0;

        //         if(i>0) up = dp[i-1][j];
        //         if(j>0) lft = dp[i][j-1];

        //         dp[i][j] = up+lft;
        //     }
        // }
        // return dp[m-1][n-1];
        vector<int> dp(n,0);
        for(int i =0; i<m; i++){
            vector<int> prev(n,0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    prev[j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    prev[j]=1;
                    continue;
                }
                int up=0, lft = 0;
                if(i>0) up = dp[j];
                if(j>0) lft = prev[j-1];

                prev[j] = up+lft;
            }
            dp = prev;
        }
        return dp[n-1];
    }
};