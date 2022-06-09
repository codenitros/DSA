// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool isValid(int i, int j, char val, vector<vector<char>>& board){
        int row=i;
        int col=j;
        // check row and col
        for(int k=0;k<9;k++){
            if(board[row][k]==val)return false;
            
            if(board[k][col]==val)return false;
        
           // check sub-box
            if(board[3 * (row/3)+ k/3][3* (col/3)+k%3]==val)return false;
        }
        return true;
    }
    

    
    bool solveUtil(vector<vector<char>>& board){
        for(int row=0; row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(row, col, c, board)){
                            board[row][col]=c;
                            if(solveUtil(board)){
                                return true;
                            }else{
                                board[row][col]='.';// backtrack
                            }
                        }
                    }
                    return false;                
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
            solveUtil(board);
    }
};