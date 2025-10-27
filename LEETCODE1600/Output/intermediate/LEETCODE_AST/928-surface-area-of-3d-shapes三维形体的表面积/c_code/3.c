int surfaceArea(int** grid, int gridSize, int* gridColSize){
	int area = 0;
	for (int i = 0; i < gridSize; i++){
		for (int j = 0; j < *gridColSize; j++){
			if (grid[i][j]){
				area += grid[i][j] * 4 + 2;
				if (i < gridSize - 1 && grid[i + 1][j])
					area -= (grid[i][j] < grid[i + 1][j] ? grid[i][j] : grid[i + 1][j]) * 2;
				if (j < *gridColSize - 1 && grid[i][j + 1])
					area -= (grid[i][j] < grid[i][j + 1] ? grid[i][j] : grid[i][j + 1]) * 2;
			}
		}
	}
	return area;
}