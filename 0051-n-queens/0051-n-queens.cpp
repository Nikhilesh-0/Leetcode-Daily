class Solution {
public:
    vector<vector<string>> ans;
    vector<string> mat;
    bool issafe(int r, int c, int &n) {
        for (int i=0; i<n; ++i) {
            if (mat[i][c] == 'Q' || mat[r][i] == 'Q') return false;
            if (r-i >= 0 && c-i >= 0 && mat[r-i][c-i] == 'Q') return false;
            if (r+i < n && c+i < n && mat[r+i][c+i] == 'Q') return false;
            if (r-i >= 0 && c+i < 0 && mat[r-i][c+i] == 'Q') return false;
            if (r+i < n && c-i >= 0 && mat[r+i][c-i] == 'Q') return false;

        }

        return true;
    }
    void find(int c, int &n) {
        if (c >= n) {
            ans.push_back(mat);
            return;
        }
        for (int r=0; r<n; ++r) {
            if(issafe(r,c,n) == true) {
                mat[r][c] = 'Q';
                find(c+1, n);
                mat[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        mat.resize(n, string(n,'.'));
        find(0,n);
        return ans;
    }
};