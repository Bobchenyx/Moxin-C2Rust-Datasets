int trap(int* height, int heightSize){
    if(heightSize<=2)
        return 0;
    
    int sumW=0,sumS=0;
    int l=0,h=heightSize-1;
    int i=1;
    int t=0;
    while(t<heightSize)
    {
        sumS+=height[t];
        t++;
    }
    while(l!=h)
    {
        while(height[l]<i&&l<h)
            l++;
        while(height[h]<i&&h>l)
            h--;
        
        if(l!=h)sumW+=h-l+1;
        else sumW+=height[l]-i+1;
        
        i++;
    }
    
    return sumW-sumS;
}