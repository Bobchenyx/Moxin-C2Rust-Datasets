int findSpecialInteger(int* arr, int arrSize)
{
    int max = arr[arrSize-1];
    int tmp[max+1];
    for(int k =0; k<=max;k++)
    {
        tmp[k] = 0;
    }

    int i=0;
    for(i=0; i<arrSize; i++)
    {
        tmp[arr[i]]++;
        if((tmp[arr[i]] != 0) && (arrSize/tmp[arr[i]] < 4))
        {
            break;
        }
    }

    return arr[i];
}