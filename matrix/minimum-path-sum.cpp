class Solution {
public:
    // int f(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
    //     if(i<0 || j<0) return 1e9;
    //     if(i==0 && j==0) return grid[0][0];

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     return dp[i][j] = grid[i][j] + min(f(grid,dp,i-1,j),f(grid,dp,i,j-1));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        
        vector<int> prev(n,0);
        for(int i = 0; i<m; i++){
            vector<int> cur(n,0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) cur[j] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i>0) up+=prev[j];
                    else up+=1e9;

                    int lft = grid[i][j];
                    if(j>0) lft +=cur[j-1];
                    else lft+=1e9;
                
                    cur[j] = min(lft,up);
                }
            }
            prev = cur;
        }
        return prev[n-1];
        // return f(grid,dp,m-1,n-1);
    }
};