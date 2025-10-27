/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
	int inx;
	int valFrom, valTo;
	int i, j;
	int ni, nj;
	char *map = NULL;
	map = (char*)calloc(gridSize * gridColSize[0], sizeof(char));
	if (map == NULL) {
		*returnSize = 0;
		return NULL;
	}
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize[i]; j++) {
			ni = i;
			nj = j;
			valFrom = grid[ni][nj];
			while (map[(ni * gridColSize[i] + nj) % (gridSize * gridColSize[i])] == 0) {
				map[ni * gridColSize[i] + nj] = 1;
				inx = (ni * gridColSize[i] + nj + k) % (gridSize * gridColSize[i]);
				ni = inx / gridColSize[i];
				nj = inx % gridColSize[i];
				valTo = grid[ni][nj];
				grid[ni][nj] = valFrom;
				valFrom = valTo;
			}
		}
	}
	free(map);
	*returnSize = gridSize;
	*returnColumnSizes = gridColSize;
	return grid;
}