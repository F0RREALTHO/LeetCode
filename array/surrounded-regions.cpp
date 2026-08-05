class Solution {
public:

    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O' || vis[x][y]) 
            return;

        vis[x][y] = 1;

        dfs(x+1, y, board, vis);
        dfs(x-1, y, board, vis);
        dfs(x, y+1, board, vis);
        dfs(x, y-1, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }
        for(int j = 0; j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,board,vis);
            }
        }

        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) continue;
                else board[i][j] = 'X';
            }
        }
    }
};