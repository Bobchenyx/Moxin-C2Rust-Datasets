/*
strcut ListNode{
    int val;
    strcut ListNode* next;
};
*/
//#include <math.h>
int reverse(int x){
    int i = 0, j = 1, k = 1;
    long y = 0;
    int min, max;
    int len;

    /* 合法性判断 */
    min = 0 - pow(2, 31);
    max = pow(2, 31) - 1;
    if ((x <= min) || (x >= max))
    {
        return 0;
    }

    /* 特殊值处理，零 */
    if (0 == x)
    {
        return 0;
    }

    if (x > 0)
    {
        k = 1;
        while(k > 0){
            k = x/((int)pow(10, i++));
        }
    }
    else{
        k = -1;
        while(k < 0){
            k = x/((int)pow(10, i++));
        }
    }
    
    len = i;
    /* 生产顺序链 */
    for (i = len - 2, k = 0; i >= 0; i--)
    {
        j = (x/((int)pow(10, i)))%10;
        y += j * pow(10, k++);
    }

    if ((int)y != y)
    {
        y = 0;
    }

    return y;
}