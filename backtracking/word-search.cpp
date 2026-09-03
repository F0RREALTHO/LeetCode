class Solution {
public:
    bool f(string s, int x, int y, vector<vector<char>>& board, string word, int n, int m, vector<pair<int,int>>& dir){
        if(s.size()==word.size()){
            return true;
        }
        // s+= board[x][y];
        for(auto [dx,dy]:dir){
            int nx = x+dx, ny =y+dy;
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]!='*' && board[nx][ny] == word[s.size()]){
                s+=board[nx][ny];
                char temp = board[nx][ny];
                board[nx][ny] = '*';
                if(f(s,nx,ny,board,word,n,m,dir)) return true;
                s.pop_back();
                board[nx][ny]=temp;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        int m= board.size();
        int n = board[0].size();

        for(int i =0; i<m; i++){
            for(int j =0;j<n;j++){
                if(board[i][j]!=word[0]) continue;
                string s ="";
                s+=board[i][j];
                char temp = board[i][j];
                board[i][j]='*';
                if(f(s,i,j,board,word,n,m,dir)==true) return true;
                board[i][j]= temp;
            }
        }
        return false;
    }
};