class Solution {
public:
    // int f(int i1 , int j1 ,int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,int n){
    //     int i2 = i1+j1-j2;
    //     if(j1>=n || j2>=n || i1>=n || i2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e8;
    //     if(i1==n-1 && j1==n-1) return grid[i1][j1];

    //     if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];

    //     int sum = 0;
    //     if(i1==i2 && j1==j2) sum+=grid[i1][j1];
    //     else sum+=grid[i1][j1] + grid[i2][j2];

    //     int dd = f(i1+1,j1,j2,grid,dp,n);
    //     int dr = f(i1+1,j1,j2+1,grid,dp,n);
    //     int rr = f(i1,j1+1,j2+1,grid,dp,n);
    //     int rd = f(i1,j1+1,j2,grid,dp,n);

    //     int maxi = max({dd,dr,rr,rd});
    //     return dp[i1][j1][j2] = maxi+sum;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(n,-1e8)));
        dp[n-1][n-1][n-1] = grid[n-1][n-1];

        for(int i1 = n-1; i1>=0; i1--){
            for(int j1=n-1; j1>=0; j1--){
                for(int j2= n-1; j2>=0; j2--){
                    int i2 = i1+j1-j2;
                    if(i2<0 || i2>=n) continue;
                    if(grid[i1][j1]==-1 || grid[i2][j2]==-1) continue;

                    if(i1==n-1 && j1==n-1 && j2==n-1) continue;
                    int sum = 0;
                    if(i1==i2 && j1==j2) sum+=grid[i1][j1];
                    else sum+=grid[i1][j1] + grid[i2][j2];

                    int dd = (i1+1<n && i2+1<n) ? dp[i1+1][j1][j2] : -1e8;
                    int dr = (i1+1<n && j2+1<n) ? dp[i1+1][j1][j2+1] : -1e8;
                    int rr = (j1+1<n && j2+1<n) ? dp[i1][j1+1][j2+1] : -1e8;
                    int rd = (j1+1<n && i2+1<n) ? dp[i1][j1+1][j2] : -1e8;

                    int maxi = max({dd,dr,rr,rd});
                    dp[i1][j1][j2] = maxi+sum;
                }
            }
        }

        // return max(0,f(0,0,0,grid,dp,n));
        return max(0,dp[0][0][0]);
    }
};