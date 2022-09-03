class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0] == 0) col0 = 0;//if any element of first col is 0 set col0 = false
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j] == 0)//if any matrix element is 0 set its coresponding
                    matrix[i][0] = matrix[0][j] = 0;//row and column to 0
            }
        }
        
        for(int i =rows-1; i>= 0;i--)//traversing in the reverse order
        {
            for(int j= cols-1; j>=1;j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)//if any of the dummy row or col element is 0
                    matrix[i][j] = 0;     //set that element to 0 
                
            }
            if(col0 == 0) matrix[i][0] = 0; //if col0 = false set col to 0
        }
    }
};

























