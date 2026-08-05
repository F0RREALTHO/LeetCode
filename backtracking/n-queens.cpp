class Solution {
public:

    bool is_safe(int row, int col, vector<string>& board, int n, vector<bool>& left_diag, vector<bool>& right_diag,vector<bool>& row_vist){
        int m_id = row+col;
        int M_id = row-col +(n-1);

        if(row_vist[row] || left_diag[m_id]|| right_diag[M_id]) return false;

        return true;
    }

    void f(vector<string>& board, int n, int col,vector<bool>& row_vist,vector<vector<string>>& ans, vector<bool>& left_diag, vector<bool>& right_diag){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(is_safe(row,col,board,n,left_diag,right_diag,row_vist)){
                int m_id = row+col;
                int M_id = row-col +(n-1);

                board[row][col] = 'Q';
                row_vist[row] = true;
                left_diag[m_id] = true;
                right_diag[M_id] = true;

                f(board,n,col+1,row_vist,ans,left_diag,right_diag);

                board[row][col] = '.';
                row_vist[row] = false;
                left_diag[m_id] = false;
                right_diag[M_id] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        vector<bool> row_vist(n,false);
        vector<bool> left_diag(2*n-1,false);
        vector<bool> right_diag(2*n-1,false);

        f(board,n,0,row_vist,ans,left_diag,right_diag);

        return ans;
    }
};