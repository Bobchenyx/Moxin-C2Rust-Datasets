int surfaceArea(int** grid, int gridSize, int* gridColSize){
	int i, j, pre;
	int x, y, z;
	x = 0;
	for (i = 0; i < gridSize; i++) {
		pre = 0;
		for (j = 0; j < gridColSize[0]; j++) {
			x += abs(grid[i][j] - pre);
			pre = grid[i][j];
		}
		x += pre;
	}
	y = 0;
	for (i = 0; i < gridColSize[0]; i++) {
		pre = 0;
		for (j = 0; j < gridSize; j++) {
			y += abs(grid[j][i] - pre);
			pre = grid[j][i];
		}
		y += pre;
	}
	z = 0;
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize[0]; j++) {
			if (grid[i][j] != 0) {
				z += 2;
			}
		}
	}
	return x + y + z;
}