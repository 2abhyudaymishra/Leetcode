class Solution {
    
public:
    void markIslandSurrounded(vector<vector<char>>& grid, int row, int col, int &rowSize, int &colSize){
        if(row>=rowSize || row<0 || col>=colSize || col<0 || grid[row][col]=='0')return;
        grid[row][col]='0';

        //up 
        markIslandSurrounded(grid, row-1,col, rowSize, colSize);
        //down
        markIslandSurrounded(grid, row+1,col, rowSize, colSize);

        //left
        markIslandSurrounded(grid, row,col-1, rowSize, colSize);

        //right
        markIslandSurrounded(grid, row,col+1, rowSize, colSize);

    }
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int numberOfIslands = 0;
        for(int row=0; row<rowSize; row++){
            for(int col=0; col<colSize; col++){
                if(grid[row][col]=='1'){
                    markIslandSurrounded(grid, row, col, rowSize, colSize);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
};