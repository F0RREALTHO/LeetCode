class Solution {
public:
    bool f(string s, int x, int y, vector<vector<char>>& board, string word, vector<vector<bool>>& vis, int n, int m, vector<pair<int,int>>& dir){
        if(s==word){
            return true;
        }
        // s+= board[x][y];
        for(auto [dx,dy]:dir){
            int nx = x+dx, ny =y+dy;
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                s+=board[nx][ny];
                vis[nx][ny]=true;
                if(f(s,nx,ny,board,word,vis,n,m,dir)) return true;
                s.pop_back();
                vis[nx][ny]=false;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        int m= board.size();
        int n = board[0].size();
        vector<vector<bool>> vis (m,vector<bool>(n,false));
        for(int i =0; i<m; i++){
            for(int j =0;j<n;j++){
                string s ="";
                s+=board[i][j];
                vis[i][j]= true;
                if(f(s,i,j,board,word,vis,n,m,dir)==true) return true;
                vis[i][j]=false;
            }
        }
        return false;
    }
};