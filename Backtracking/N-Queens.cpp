// https://leetcode.com/problems/n-queens/


class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        
        // check left horizontal
        int temprow = row;
        int tempcol = col;
        
        while(tempcol>=0){
            if(board[temprow][tempcol]=='Q')return false;
            tempcol--;
        }
        
        
        // check upper diagonal
        temprow=row;
        tempcol=col;
        while(temprow>=0 && tempcol>=0){
            if(board[temprow][tempcol]=='Q')return false;
            temprow--;
            tempcol--;
        }
        
        
        // check lower diaginal
        temprow=row;
        tempcol=col;
        while(temprow<n && tempcol>=0){
            if(board[temprow][tempcol]=='Q')return false;
            temprow++;
            tempcol--;
        }
        
        return true;
    }
    
    
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

