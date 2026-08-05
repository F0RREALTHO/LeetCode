class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10][10]={0};
        int col[10][10] ={0};
        int box[10][10]={0};

        for(int i =0; i<9;i++){
            for(int j = 0; j<9;j++){
                if(board[i][j]=='.') continue;

                int num = board[i][j]-'1';
                int b = (i/3)*3 + (j/3);

                if(row[i][num] || col[j][num] || box[b][num]) return false;

                row[i][num]=col[j][num] = box[b][num] = 1;
            }
        }
        return true;
    }
};