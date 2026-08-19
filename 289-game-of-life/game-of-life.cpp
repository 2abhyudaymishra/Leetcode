class Solution {
    vector<vector<int>> indexes = { {0,-1}, {0, 1}, {1, 0},{-1,0}, {-1,-1}, {1, 1} , {-1, 1}, {1, -1}}; 
public:
    int countLive(vector<vector<int>>& board, int i , int j, int &rowSize, int &colSize){
        int count=0;
        for(auto ind : indexes){
            int row = i + ind[0];
            int col = j+ ind[1];
            if(row>=0 && row<rowSize && col>=0 && col<colSize && board[row][col])count++;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy(board);
        int colSize = board[0].size();
        int rowSize = board.size();

        for(int i = 0; i<rowSize;i++){
            for(int j=0; j<colSize; j++){
                int liveCount = countLive(copy, i, j, rowSize, colSize);
                if(board[i][j]==0){
                    if(liveCount==3)board[i][j]=1;
                }else{
                    if(liveCount<2 || liveCount>3)board[i][j]=0;
                    else board[i][j]=1;
                }
            }
        }
    }
};