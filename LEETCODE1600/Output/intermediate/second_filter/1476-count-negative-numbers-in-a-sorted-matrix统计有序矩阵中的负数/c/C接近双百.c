int countNegatives( int ** grid , int gridSize , int * gridColSize)
{
    int count = 0;
    for( int i = gridSize - 1 ; i >= 0  ; i-- )
	{
        int j = *( gridColSize + i ) - 1;
        if( *( *( grid + i ) + j ) >= 0 )
		{
            return count;
        }
        for(  ; j >= 0 ;j-- )
		{
            if( *( *( grid + i ) + j ) >= 0 )
			{
                break;
            }
            count++;
        }
    }
    return count;
}