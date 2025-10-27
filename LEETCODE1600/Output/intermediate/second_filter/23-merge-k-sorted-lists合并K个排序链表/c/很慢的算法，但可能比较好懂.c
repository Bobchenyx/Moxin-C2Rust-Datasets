typedef struct ListNode *List;

List
mergeKLists( List *lists, int listsSize )
{
	List Head = NULL, P = NULL;
	int i = 0, min = 0, minPos = listsSize - 1;
	int flag = 1;

	Head = calloc( 1, sizeof( struct ListNode ) );
	Head->next = NULL;
	P = Head;


	while ( flag == 1 )
	{
		flag = 0;
		min = INT_MAX;
		for ( i = 0; i < listsSize; i++ )
		{
			if ( lists[ i ] != NULL )
			{
				if ( lists[ i ]->val <= min )
				{
					min = lists[ i ]->val;
					minPos = i;
					flag = 1;
				}
			}
		}

		if ( flag == 1 )
		{
			P->next = lists[ minPos ];
			lists[ minPos ] = lists[ minPos ]->next;
			P = P->next;
		}
	}

	P = Head->next;
	free( Head );
	
	return P;
}