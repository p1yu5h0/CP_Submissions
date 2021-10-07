class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area, area_near_that_block(grid, i, j));
                }
            }
        }
        return max_area;
    }
    
    int area_near_that_block(vector<vector<int>>& grid, int i, int j){
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + area_near_that_block(grid, i+1, j) + area_near_that_block(grid, i-1, j) +
                area_near_that_block(grid, i, j-1) + area_near_that_block(grid, i, j+1);
        } 
        return 0;
    }
};
/*
- we move through every block and do a dfs on each block and check the area by that block
- on each block we do a dfs and greedly find out our max answer
*/