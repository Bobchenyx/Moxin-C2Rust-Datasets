bool canMeasureWater(int x, int y, int z){
    if(x+y<z) return false;
    if(z==0) return true; 
    if(x==0||y==0) return (x+y)==z;

    int i=x;
    if(y<x) i=y;
    for( ;i>=1 ;i--)
    {
        if(x%i==0&&y%i==0) break;
    }
    
    for(int j=1;j<=z;j++)
    {
        if(j*i ==z) return true;
    }

    return false;

}