class Solution {
public:
    bool issafe(int r, int c, vector<vector<char>> &board) {
        int ir = r/3*3;
        int ic = c/3*3;
        for(int i=0; i<9; ++i) {
            if (board[r][i] == board[r][c] && i != c) {
                return false;
            } 
            if (board[i][c] == board[r][c] && i!= r) {
                return false;
            }
            int nr = ir+i/3;
            int nc = ic+i%3;
            if (r == nr && c == nc) continue;
            if(board[r][c] == board[nr][nc]) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            for(int j = 0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                if (issafe(i,j,board) == false) return false;
            }
        }
        return true;
    }
};