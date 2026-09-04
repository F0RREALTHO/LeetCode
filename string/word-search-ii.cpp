class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};

    bool f(int idx, int x, int y, vector<vector<char>>& board, string& word, int n, int m){
        if(idx==word.size()){
            return true;
        }

        char tar = word[idx];
        for(int i =0; i<4;i++){
            int nx = x+dx[i], ny =y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]==tar){
                board[nx][ny] = '*';
                if(f(idx+1,nx,ny,board,word,n,m)){
                    board[nx][ny]=tar;
                    return true;
                }
                board[nx][ny]=tar;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string &word, vector<int>& cnt, int &n, int &m) {
        if(word.size()>m*n) return false;

        int nd[256]={0};
        for(char c:word){
            nd[c]++;
            if(nd[c]>cnt[c]) return false;
        }
        
        int l = 0, r = word.size()-1;
        bool rev = false;
        while(l<r && cnt[word[l]]==cnt[word[r]]){
            l++; r--;
        }
        if(l<r && cnt[word[l]]>cnt[word[r]]){
            reverse(word.begin(),word.end());
            rev=true;
        }
        

        bool fnd = false;
        for(int i =0; i<m; i++){
            for(int j =0;j<n;j++){
                if(board[i][j]!=word[0]) continue;
                char temp = board[i][j];
                board[i][j]='*';
                if(f(1,i,j,board,word,n,m)==true){
                    board[i][j]=temp;
                    fnd= true;
                    break;
                }
                board[i][j]= temp;
            }
            if (fnd) break;
        }

        if(rev) reverse(word.begin(),word.end());
        return fnd;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int m= board.size();
        int n = board[0].size();

        vector<int> cnt(256,0);
        for(int i =0; i<m;i++){
            for(int j=0;j<n;j++){
                cnt[board[i][j]]++;
            }
        }

        for(string& word : words) {
            if(exist(board, word,cnt,n,m))
                ans.push_back(word);
        }

        

        return ans;
    
    }
};