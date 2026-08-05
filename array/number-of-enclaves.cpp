class Solution {
public:

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || grid[x][y]==0) return;

        vis[x][y] = 1;
        dfs(x+1,y,grid,vis);
        dfs(x-1,y,grid,vis);
        dfs(x,y+1,grid,vis);
        dfs(x,y-1,grid,vis);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i =0; i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }

        int numberOfEnclaves = 0;
        for(int i=0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) numberOfEnclaves++;
            }
        }
        
        return numberOfEnclaves;
    }
};