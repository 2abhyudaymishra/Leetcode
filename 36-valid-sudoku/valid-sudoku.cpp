class Solution {
public:
    bool isValidInput(vector<vector<char>>& board,int row, int col ){
        char n = board[row][col];
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==n )return false;
            if(i!=col && board[row][i]==n)return false;
        }

        int rowStart = 3* (row/3) ;
        int colStart =  3* (col/3);
        int boxRowEnd = rowStart+3;
        int boxColEnd = colStart+3;
        for( int i =rowStart; i<boxRowEnd;i++){
            for(int j = colStart; j<boxColEnd; j++){
                if(i==row && j==col)continue;
                if(board[i][j]==n){
                    return false;
                }
            }
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;

                if(!isValidInput(board, i, j)){
                    return false;
                }
                
            }
        }
        return true;
    }
};