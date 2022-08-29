class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    func(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void func(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size())//if it goes out of bound
            return;
        if(grid[i][j] == '0') return ;
        grid[i][j]='0'; //we are making it 0 so that function call do not repeat itself at that value again and again
        func(grid, i+1,j);
        func(grid, i-1,j);
        func(grid,i, j+1);
        func(grid,i , j-1);
    }
};