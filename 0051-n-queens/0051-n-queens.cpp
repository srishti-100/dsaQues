class Solution {
public:
/*
    helper(int rows, int cols, int r, int c, vector<vector<char>>& ans){
        if(r>=rows){
            return true;
        }

        if(c>=cols){
            return helper(rows, cols, r+1, 0, ans);
        }

        //row clearance
        for(int i = 0; i<r; i++){
            if(ans[i][c] == 'Q') return false;
        }

        //column clearance
        for(int i = 0; i<c; i++){
            if(ans[r][i]=='Q') return false;
        }

        //diagonal clearance

        for(int i = r-1, j = c-1; i>=0 && j>=0; i--,j--){
            if(ans[i][j]=='Q') return false;
        }

        for(int i = r-1, j= c+1; i>=0 && j<cols; i--, j++){
            if(ans[i][j]=='Q') return false;
        }

        ans[r][c]='Q';
        helper(rows, cols, r+1,0, ans);
        ans[r][c]='.';
    }

*/
    bool isSafe(int r, int c, vector<vector<char>>& board, int n){
       

        //column clearance
        for(int i = 0; i<c; i++){
            if(board[r][i]=='Q') return false;
        }

        //diagonal clearance

        for(int i = r, j = c; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }

        for(int i = r, j= c; i<n && j>=0; i++, j--){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }

    void helper(int c,vector<vector<char>>& board, vector<vector<string>>&ans, int n){
        if(c>=n){
            vector<string> temp;
            for(int i = 0; i<n; i++){
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }

            ans.push_back(temp);
        }

        for(int i =0; i<n; i++){
            if(isSafe(i,c,board, n)){
                board[i][c] = 'Q';
                helper(c+1,board,ans,n);
                board[i][c]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        helper(0,board, ans, n);
        return ans;
    }
};