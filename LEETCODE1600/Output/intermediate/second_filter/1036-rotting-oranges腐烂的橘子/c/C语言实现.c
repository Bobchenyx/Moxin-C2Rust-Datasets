int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int k = 3;
	int res = 0;
	int flag = 0;
	while (flag == 0) {
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < *gridColSize; j++) {
				if (grid[i][j] == 1) {	
					if (i != 0 && grid[i - 1][j] > 1 && grid[i - 1][j] < k) {
						// up
						grid[i][j] = k;
						flag = 1;
					} else if (i < gridSize - 1 && grid[i + 1][j] > 1 && grid[i + 1][j] < k) {
						// down
						grid[i][j] = k;
						flag = 1;
					} else if (j != 0 && grid[i][j - 1] > 1 && grid[i][j - 1] < k) {
						// left
						grid[i][j] = k;
						flag = 1;
					} else if (j < *gridColSize - 1 && grid[i][j + 1] > 1 && grid[i][j + 1] < k) {
						// right
						grid[i][j] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag) {
			k++;
			flag = 0;
		} else {
			break;
		}
	}
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1) {
				return -1;
			}
		}
	}
	res = k - 3;
	return res;
}