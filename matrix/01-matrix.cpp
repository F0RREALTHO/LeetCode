class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<tuple<int,int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }

        while(!q.empty()){
            auto[x,y,d] = q.front();
            q.pop();
            ans[x][y] = d;
            for(auto [dx,dy]:dir){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx,ny,d+1});
                }
            }
        }
        return ans;
    }
};