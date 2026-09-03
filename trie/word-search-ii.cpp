class Solution {
public:

    bool f(int idx, int x, int y, vector<vector<char>>& board, string word, int n, int m, vector<pair<int,int>>& dir){
        if(idx==word.size()){
            return true;
        }
        for(auto [dx,dy]:dir){
            int nx = x+dx, ny =y+dy;
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]!='*' && board[nx][ny] == word[idx]){
                char temp = board[nx][ny];
                board[nx][ny] = '*';
                if(f(idx+1,nx,ny,board,word,n,m,dir)){
                    board[nx][ny]=temp;
                    return true;
                }
                board[nx][ny]=temp;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string &word) {
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        int m= board.size();
        int n = board[0].size();

        if(word.size()>m*n) return false;
        
        for(int i =0; i<m; i++){
            for(int j =0;j<n;j++){
                if(board[i][j]!=word[0]) continue;
                char temp = board[i][j];
                board[i][j]='*';
                if(f(1,i,j,board,word,n,m,dir)==true){
                    board[i][j]=temp;
                    return true;
                }
                board[i][j]= temp;
            }
        }
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        for(string& word : words) {
            if(exist(board, word))
                ans.push_back(word);
        }

        return ans;
    
    }
};