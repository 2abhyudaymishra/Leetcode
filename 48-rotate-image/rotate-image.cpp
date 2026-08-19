class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowStart=0;
        int colStart=0;
        int rowEnd = matrix.size()-1;
        int colEnd = rowEnd;

        while(rowStart<rowEnd && colStart<colEnd){
            for(int i=rowStart, j = colStart; i<rowEnd && j<colEnd; i++, j++){
                swap(matrix[i][colEnd], matrix[rowStart][j]);
            }

            for(int i=colEnd, j=colStart; i>colStart && j<colEnd; i-- , j++){
                swap(matrix[rowEnd][i], matrix[rowStart][j]);
            }

            for(int i=rowEnd, j=colStart; i>rowStart && j<colEnd; i--, j++){
                swap(matrix[i][colStart], matrix[rowStart][j]);
            }
            colStart++;
            rowStart++;
            colEnd--;
            rowEnd--;
        }
    }
};