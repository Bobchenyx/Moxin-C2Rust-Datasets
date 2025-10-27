int mySqrt(int x)
{
    if(x == 1) return 1;
    int n = x / 2;
    long int i;
    for(i=0; i<n; i++)
    {
        if(i*i == x) break;
        if(i*i<x && (i+1)*(i+1)>x) break; 
    }
    return i;
}