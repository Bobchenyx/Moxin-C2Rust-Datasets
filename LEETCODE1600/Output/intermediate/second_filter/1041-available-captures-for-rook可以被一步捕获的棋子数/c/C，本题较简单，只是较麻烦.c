int numRookCaptures(char** board, int boardSize, int* boardColSize){
	int res = 0;
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < *boardColSize; j++){
			if (board[i][j] == 'R'){
				for (int l = j - 1; l >= 0; l--){
					if (board[i][l] == 'B')
						break;
					else if (board[i][l] == 'p'){
						res++;
						break;
					}
				}
				for (int r = j + 1; r <*boardColSize; r++){
					if (board[i][r] == 'B')
						break;
					else if (board[i][r] == 'p'){
						res++;
						break;
					}
				}
				for (int u = i - 1; u >= 0; u--){
					if (board[u][j] == 'B')
						break;
					else if (board[u][j] == 'p'){
						res++;
						break;
					}
				}
				for (int d = i + 1; d<boardSize; d++){
					if (board[d][j] == 'B')
						break;
					else if (board[d][j] == 'p'){
						res++;
						break;
					}
				}
				break;
			}
		}
	}
	return res;
}