class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rowCount = grid1.size();
        int colCount = grid1[0].size();
        int subIslandCount = 0;
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                if (grid2[row][col] == 1 && depthFirstSearch(row, col, rowCount, colCount, grid1, grid2)) {
                    ++subIslandCount;
                }
            }
        }
        return subIslandCount;
    }
    bool depthFirstSearch(int row, int col, int rowCount, int colCount, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool isSubIsland = grid1[row][col] == 1;
        grid2[row][col] = 0;
        vector<int> directions = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int nextRow = row + directions[k];
            int nextCol = col + directions[k + 1];          
            if (nextRow >= 0 && nextRow < rowCount && 
                nextCol >= 0 && nextCol < colCount && 
                grid2[nextRow][nextCol] == 1) {
                if (!depthFirstSearch(nextRow, nextCol, rowCount, colCount, grid1, grid2)) {
                    isSubIsland = false;
                }
            }
        }      
        return isSubIsland;
    }
};