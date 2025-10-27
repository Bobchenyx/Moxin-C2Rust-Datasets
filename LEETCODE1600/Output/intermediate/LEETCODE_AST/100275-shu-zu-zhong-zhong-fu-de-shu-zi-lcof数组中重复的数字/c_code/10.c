/**
*
*整体思路：
*1.快速排序原数组
*2.从下标为1开始遍历数组，
*3.比较i与i-1元素是否相同，如果是，直接返回i元素，否则更新i，继续步骤3，直到i==numsSize时进入步骤4
*4.返回-1
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int findRepeatNumber( int * nums , int numsSize ){

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //visiting array
    for( int i = 1 ; i < numsSize ; i++ ){

        //if the value of current element equals to the value of former element, returning
        //the value of current element  
        if( *( nums + i ) == *( nums + i - 1 ) ){

            return *( nums + i );

        }

    }

    return -1;

}