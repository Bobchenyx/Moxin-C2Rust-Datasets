/**
*
*整体思路：
*1.申请动态内存，存储每个人被信任的情况，以及每个人是否有信任的人
*2.清空缓冲区，
*3.遍历信任数组，对缓冲区信任的人进行投票，并记录自己编号
*4.遍历缓冲区，如果有一个人被信任了N-1次，且不信任任何人，他就是法官，返回其编号
*5.返回-1
*/

int findJudge( int N , int ** trust , int trustSize , int * trustColSize ){

    //if the length of trust is less than 1, return 1
    if( N < 1 || trustSize < 1 ){

        return 1;

    }

    //alloclating memory to mark everyone's note
    int * buffer = ( int * )malloc( sizeof( int ) * N );

    //clearing the memory
    for( int i = 0 ; i < N ; i++ ){

        *( buffer + i ) = 0;

    }

    //calculating the number of notes in everyone
    for( int i = 0 ; i < trustSize ; i++ ){

        *( buffer + *( *( trust + i ) + 0 ) - 1 ) 
                            = 10000 + *( buffer + *( *( trust + i ) + 0 ) - 1 );
        *( buffer + *( *( trust + i ) + 1 ) - 1 ) += 1;

    }

    //trying to find the judge
    for( int i = 0 ; i < N ; i++ ){

        if( *( buffer + i ) % 10000 == N - 1 && *( buffer + i ) / 10000 == 0 ){

            free( buffer );
            return i + 1;

        }

    }

    //can not find the judge
    free( buffer );
    return -1;

}