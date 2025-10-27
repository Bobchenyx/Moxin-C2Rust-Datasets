/**
*
*整体思路：
*1.从后往前，存放nums1和nums2最大的元素到nums1的最后，
*2.维护三个指针，指针k指向nums1当前存放的位置，k初始化指向nums1最后一个元素,即nums1Size-1
*  i指向当前nums1有效的元素，i初始化指向m-1
*  j指向当前nums2有效的元素，j初始化指向n-1
*3.用k遍历数组nums1，并判断k>=0是否成立
*4.如果i小于0，证明nums1元素已存放完毕，这时直接把nums2所有元素存入*( nums1 + k )后续即可，退出遍历
*  如果j小于0，证明nums2元素已存放完毕，退出遍历
*5.否则比较*( nums1 + i ) 和 *( nums2 + j )，将较大的元素存入*( nums1 + k )
*6.继续下一趟遍历
*/


void merge( int * nums1 , int nums1Size , int m , int * nums2 , int nums2Size , int n ){

    //the parameter of i is the pointer of nums1 from 0 to m-1
    //the parameter of j is the pointer of nums2 from 0 to n-1
    int i = m - 1 , j = n - 1;

    //using the pointer of k to visiting nums1
    for( int k = nums1Size - 1 ;  k >= 0 ; k-- ){

        //if all the elements in nums1 have been sorted already, 
        //copying the rest elements in nums2 to nums1 
        if( i < 0 ){

            while( k >= 0 ){

                *( nums1 + k-- ) = *( nums2 + j-- );

            }

            break;

        //if all the elements in nums2 have been sorted already, breaking loop
        } else if( j < 0 ){

            break;

        }

        //saving the elements to nums1 according to 
        //the value of current element in nums1 and nums2
        if( *( nums1 + i ) > *( nums2 + j ) ){

            *( nums1 + k ) = *( nums1 + i-- );

        } else {

            *( nums1 + k ) = *( nums2 + j-- );

        }

    }

}