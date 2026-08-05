class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }else if(grid[i][j]==1) cnt++;
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int min = 0;

        while(!q.empty()){
            auto[x,y,t] = q.front();
            q.pop();
            min = max(min,t);

            for(auto [dx,dy]:dir){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                    cnt--;
                    vis[nx][ny]=1;
                    q.push({nx,ny,t+1});
                }
            }
        }
        return (cnt==0?min:-1);
    }
};