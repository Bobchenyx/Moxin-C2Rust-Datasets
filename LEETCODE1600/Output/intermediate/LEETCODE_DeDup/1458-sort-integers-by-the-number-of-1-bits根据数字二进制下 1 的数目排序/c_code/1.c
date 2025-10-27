/**
*
*整体思路：
*1.利用二维数组buffer，下标为0的元素存储arr中元素二进制1的个数，下标1的元素存储arr的元素值
*2.利用快速排序，
*   如果当前二进制1的个数相等，比较元素值大小
*3.将buffer所有数组中下标为1的元素复制到arr
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*Function: calculating the number of 1 in the binary of value
*@param: int value : the value ready to be checked
*return: the result of the process
*/
int binaryNum( int value ){

    //the parameter of count is used to rememmber the number of 1 in the binary of value
    int count = 0;

    //calculating the binary of value
    while( value > 0 ){

        if( value % 2 == 1 ){

            count++;

        }

        value /= 2;

    }

    return count;

}

/**
*Funciton: the fun is used in qsort
*@param: const void * a : the first element ready to be compared
*@param: const void * b : the second element ready to be compared
*return: int : 
*/
int cmp( const void * a , const void * b ){

    int tmp = *( *( ( int ** ) a ) + 0 ) - *( *( ( int ** ) b ) + 0 );

    //if the value of first element in array a and b is equaling
    if( tmp == 0 ){

        //sorting them by their original value
        return *( *( ( int ** ) a ) + 1 ) - *( *( ( int ** ) b ) + 1 );

    }

    return tmp;

}

int * sortByBits( int * arr , int arrSize , int * returnSize ){

    //intializing the length of arr
    *returnSize = arrSize;

    //alloclating memory to save the number of 1 in binary of arr's value and it's value
    int ** buffer = ( int * )malloc( sizeof( int * ) * arrSize );

    //intializing the buffer
    for( int i = 0 ; i < arrSize ; i++ ){

        *( buffer + i ) = ( int * )malloc( sizeof( int ) * 2 );

        *( *( buffer + i ) + 0 ) = binaryNum( *( arr + i ) );
        *( *( buffer + i ) + 1 ) = *( arr + i );

    }

    qsort( buffer , arrSize , sizeof( *( buffer + 0 ) ) , cmp );

    //copying the second elements of each array in buffer to arr
    for( int i = 0 ; i < arrSize ; i++ ){

        *( arr + i ) = *( *( buffer + i ) + 1 );

    }

    return arr;

}