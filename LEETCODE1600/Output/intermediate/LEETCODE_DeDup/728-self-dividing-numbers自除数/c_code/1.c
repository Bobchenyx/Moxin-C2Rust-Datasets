/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){

int (*p) = (int *) malloc(sizeof(int)*(right - left + 1));
int num , k = 0;

for ( num = left; num <= right ; num++)
{
    int temp = num;
    while(temp)
    {
        int fig = temp % 10;
        if(fig == 0)
        {
            break;
        }
        if (num % fig != 0)
        {
            break;
        }
        temp =temp / 10;
    }

    if (temp == 0 )
    {
        p[k] = num;
        k++;
    }
}
*returnSize = k;
return p;
}