class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]) {
                    cnt++;
                    q.push({i,j});
                    vis[i][j]=1;

                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        for(auto [dx,dy]:dir){
                            int nx = x+dx;
                            int ny = y+dy;

                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1'
                            && !vis[nx][ny]){
                                q.push({nx,ny});
                                vis[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};