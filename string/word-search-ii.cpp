class Solution {
public:

    bool f(int idx, int x, int y, vector<vector<char>>& board, string& word, int n, int m, vector<pair<int,int>>& dir){
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

        vector<int> cnt(256,0);
        for(int i =0; i<m;i++){
            for(int j=0;j<n;j++){
                cnt[board[i][j]]++;
            }
        }

        vector<int> nd(256,0);
        for(char c:word){
            nd[c]++;
            if(nd[c]>cnt[c]) return false;
        }
        string w  = word;
        if(cnt[w[0]]>cnt[w.size()-1])
            reverse(w.begin(),w.end());

        
        for(int i =0; i<m; i++){
            for(int j =0;j<n;j++){
                if(board[i][j]!=w[0]) continue;
                char temp = board[i][j];
                board[i][j]='*';
                if(f(1,i,j,board,w,n,m,dir)==true){
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