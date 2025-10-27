int area(int**grid, int i, int j, int x, int y){
	int num = 0;
	if (i > 0)
		num += grid[i - 1][j];
	if (i > 0 && j > 0)
		num += grid[i - 1][j - 1];
	if (i > 0 && j < y - 1)
		num += grid[i - 1][j + 1];
	if (j > 0)
		num += grid[i][j - 1];
	if (j < y - 1)
		num += grid[i][j + 1];
	if (i < x - 1)
		num += grid[i + 1][j];
	if (i < x - 1 && j > 0)
		num += grid[i + 1][j - 1];
	if (i < x - 1 && j < y - 1)
		num += grid[i + 1][j + 1];
	return num;
}
void gameOfLife(int** board, int boardSize, int* boardColSize){
	if (boardSize + *boardColSize < 4){
		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < *boardColSize; j++)
			    board[i][j] = 0;
		return;
	}
	int **t = (int**)malloc(sizeof(int*)*boardSize), num;
	for (int i = 0; i < boardSize; i++){
		t[i] = (int*)malloc(sizeof(int)*(*boardColSize));
		for (int j = 0; j < *boardColSize; j++){
			num = area(board, i, j, boardSize, *boardColSize);
			if (1 == board[i][j])				
				t[i][j] = (num == 2 || num == 3) ? 1 : 0;
			else
				t[i][j] = (num == 3) ? 1 : 0;			
		}
	}
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < *boardColSize; j++)
			board[i][j] = t[i][j];		
		free(t[i]);
	}
	free(t);
}