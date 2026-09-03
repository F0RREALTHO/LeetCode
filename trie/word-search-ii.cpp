class Solution {
public:

    bool f(int idx, int x, int y,
           vector<vector<char>>& board,
           string& word,
           int n, int m) {

        if(idx == word.size())
            return true;

        // down
        if(x + 1 < m &&
           board[x + 1][y] != '*' &&
           board[x + 1][y] == word[idx]) {

            char temp = board[x + 1][y];
            board[x + 1][y] = '*';

            if(f(idx + 1, x + 1, y, board, word, n, m))
                return board[x + 1][y] = temp, true;

            board[x + 1][y] = temp;
        }

        // right
        if(y + 1 < n &&
           board[x][y + 1] != '*' &&
           board[x][y + 1] == word[idx]) {

            char temp = board[x][y + 1];
            board[x][y + 1] = '*';

            if(f(idx + 1, x, y + 1, board, word, n, m))
                return board[x][y + 1] = temp, true;

            board[x][y + 1] = temp;
        }

        // up
        if(x > 0 &&
           board[x - 1][y] != '*' &&
           board[x - 1][y] == word[idx]) {

            char temp = board[x - 1][y];
            board[x - 1][y] = '*';

            if(f(idx + 1, x - 1, y, board, word, n, m))
                return board[x - 1][y] = temp, true;

            board[x - 1][y] = temp;
        }

        // left
        if(y > 0 &&
           board[x][y - 1] != '*' &&
           board[x][y - 1] == word[idx]) {

            char temp = board[x][y - 1];
            board[x][y - 1] = '*';

            if(f(idx + 1, x, y - 1, board, word, n, m))
                return board[x][y - 1] = temp, true;

            board[x][y - 1] = temp;
        }

        return false;
    }


    bool exist(vector<vector<char>>& board,
               string& word,
               vector<int>& cnt,
               vector<vector<pair<int,int>>>& pos,
               bool adj[26][26]) {

        int m = board.size();
        int n = board[0].size();

        if(word.size() > m * n)
            return false;

        // Character frequency pruning
        vector<int> need(26, 0);

        for(char c : word) {
            need[c - 'a']++;

            if(need[c - 'a'] > cnt[c - 'a'])
                return false;
        }

        // Adjacent-character pruning
        // Every consecutive pair in the word must exist
        // somewhere as neighboring cells on the board.
        for(int i = 1; i < word.size(); i++) {
            int a = word[i - 1] - 'a';
            int b = word[i] - 'a';

            if(!adj[a][b])
                return false;
        }

        string w = word;

        // Start from the rarer endpoint
        if(cnt[w[0] - 'a'] > cnt[w.back() - 'a'])
            reverse(w.begin(), w.end());


        // Only try cells containing the first character
        for(auto [x, y] : pos[w[0] - 'a']) {

            char temp = board[x][y];
            board[x][y] = '*';

            if(f(1, x, y, board, w, n, m)) {
                board[x][y] = temp;
                return true;
            }

            board[x][y] = temp;
        }

        return false;
    }


    vector<string> findWords(vector<vector<char>>& board,
                              vector<string>& words) {

        int m = board.size();
        int n = board[0].size();

        // -----------------------------------
        // 1. Character frequency of board
        // -----------------------------------

        vector<int> cnt(26, 0);

        // -----------------------------------
        // 2. Positions of each character
        // -----------------------------------

        vector<vector<pair<int,int>>> pos(26);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int c = board[i][j] - 'a';

                cnt[c]++;
                pos[c].push_back({i, j});
            }
        }


        // -----------------------------------
        // 3. Which character pairs are adjacent
        // -----------------------------------

        bool adj[26][26] = {};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int c = board[i][j] - 'a';

                if(i + 1 < m) {
                    int d = board[i + 1][j] - 'a';

                    adj[c][d] = true;
                    adj[d][c] = true;
                }

                if(j + 1 < n) {
                    int d = board[i][j + 1] - 'a';

                    adj[c][d] = true;
                    adj[d][c] = true;
                }
            }
        }


        // -----------------------------------
        // 4. Search every word
        // -----------------------------------

        vector<string> ans;

        for(string& word : words) {

            if(exist(board, word, cnt, pos, adj))
                ans.push_back(word);
        }

        return ans;
    }
};