int maxArea(int* height, int heightSize){
    if(heightSize==0||heightSize==1) return 0;
    int *p=&height[0],*q=&height[heightSize-1],h=*p<*q?*p:*q,b=heightSize-1,v=b*h;
    while(heightSize-2){
        --b;
        if(h==*p){
            ++p;
        }else{
            --q;
        }
        h=*p<*q?*p:*q;
        v=v>b*h?v:b*h;
        --heightSize;
    }
    return v;
}