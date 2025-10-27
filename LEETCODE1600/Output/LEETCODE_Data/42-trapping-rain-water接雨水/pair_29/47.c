int find_r(int i, int heightSize, int height[], int l)
{
    int max1 = l, max2 = 0, j, r;
    for(j = i + 1;j < heightSize;j++)
    {
        if(height[j] > max1)
        {
            max1 = height[j];
            break;
        }
        if(height[j] > max2 && height[j] <= l)
        {
            max2 = height[j];
        }
    }
    if(max1 > l)
    {
        r = max1;
    }
    else
    {
        r = max2;
    }
    return r;
}

int trap(int* height, int heightSize){
    int i;
    if(heightSize <= 1)
        return 0;
    int l = height[0], r, sum = 0;
    r = find_r(0, heightSize, height, l);
    for(i = 1;i < heightSize;i++)
    {
        if(height[i] >= r)
        {
            l = r;
            r = find_r(i, heightSize, height, l);
            continue;
        }
        else
        {
            if(r < l)
            {
                sum += r - height[i];
            }
            else
            {
                sum += l - height[i];
            }
        }
    }
    return sum;
}