/**
*
*整体思路：
*1.从area的平方根开始，倒序遍历1-sqrt( area )之间的数
*2.一旦找到一个长宽，该长宽一定是差值最小的一组长宽
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * constructRectangle( int area , int * returnSize){
    
    unsigned int * buffer = ( unsigned int * )malloc( sizeof( unsigned int ) * 2 );
    
    *( buffer + 0 ) = sqrt( area );
    *returnSize = 2;

    while( *( buffer + 0 ) > 0  ){

        if( area % *( buffer + 0 ) == 0 ){

            *( buffer + 1 ) = *( buffer + 0 );
            *( buffer + 0 ) = area / *( buffer + 1 );

            break;

        }

        *( buffer + 0 ) -= 1;

    }
    
    return buffer;

}