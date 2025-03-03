#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int colSize = gridColSize[0];
    int dp[gridSize][colSize];

    dp[0][0] = grid[0][0];

    for(int i = 1; i < gridSize; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int j = 1; j < colSize; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < gridSize; i++){
        for(int j = 1; j < colSize; j++){
            dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[gridSize-1][colSize-1];
}

int main() {
    int row1[] = {1, 3, 1};
    int row2[] = {1, 5, 1};
    int row3[] = {4, 2, 1};

    int* grid[] = {row1, row2, row3};
    int gridSize = 3;
    int gridColSize[] = {3};

    printf("Input: grid = [[1,3,1],[1,5,1],[4,2,1]]\nOutput: %d\n", minPathSum(grid, gridSize, gridColSize));

    int row4[] = {1, 2, 3};
    int row5[] = {4, 5, 6};

    int* grid2[] = {row4, row5};
    gridSize = 2;
    gridColSize[0] = 3;

    printf("Input: grid = [[1,2,3],[4,5,6]]\nOutput: %d\n", minPathSum(grid2, gridSize, gridColSize));

    return 0;
}
