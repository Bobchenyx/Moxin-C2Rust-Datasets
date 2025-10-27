void
set( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]++;
	col[ j ][ num ]++;
	square[ tmp ][ num ]++;
}

void
reset( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]--;
	col[ j ][ num ]--;
	square[ tmp ][ num ]--;
}

int
check( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	if ( row[ i ][ num ] + 1 > 1 )
		return 0;
	if ( col[ j ][ num ] + 1 > 1 )
		return 0;
	if ( square[ tmp ][ num ] + 1 > 1 )
		return 0;


	return 1;
}

int 
recursion( int i, int j, int **row, int **col, int **square, char **board )
{
	int k = 0, flag = 0; 
	char num = 0;

	if ( !( i == 9 && j == 0 ) )
	{
		if ( board[ i ][ j ] == '.' )
		{
			for ( k = 1; k < 10 && flag == 0; k++ )
			{
				num = ( char )k + '0';
				if ( check( i, j, row, col, square, 
							num ) == 1 )
				{
					set( i, j, row, col, square, num );
					board[ i ][ j ] = num;

					if ( j < 8 )
						flag = recursion( i, j + 1, row, col, 
								square, board );
					else
						flag = recursion( i + 1, 0, row, col, 
								square, board );

					if ( flag == 0 )
					{
						reset( i, j, row, col, square, num );
						board[ i ][ j ] = '.';
					}
				}
			}
		}
		else
		{
			if ( j < 8 )
				flag = recursion( i, j + 1, row, col, square, board );
			else
				flag = recursion( i + 1, 0, row, col, square, board );
		}
	}
	else
		return 1;

	if ( flag == 1 )
		return 1;
	return 0;
}

void
solveSudoku( char **board, int boardSize, int *boardColSize )
{
	int **row = NULL, **col = NULL, **square = NULL;
	int i = 0, j = 0; 

	row = calloc( 10, sizeof( int * ) );
	col = calloc( 10, sizeof( int * ) );
	square = calloc( 10, sizeof( int * ) );

	for ( i = 0; i < 9; i++ )
	{
		row[ i ] = calloc( 12, sizeof( int ) );
		col[ i ] = calloc( 12, sizeof( int ) );
		square[ i ] = calloc( 12, sizeof( int ) );
	}

	for ( i = 0; i < 9; i++ )
		for ( j = 0; j < 9; j++ )
			if ( board[ i ][ j ] != '.' )
				set( i, j, row, col, square, board[ i ][ j ] );

	recursion( 0, 0, row, col, square, board ); 

}