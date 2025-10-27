int trap(int* height, int heightSize){
int i,maxi,maxtmp,sum;
maxi=0;sum=0;
for(i=0;i<heightSize;i++){
    maxi=(height[i]>height[maxi])?i:maxi;
}
maxtmp=0;
for(i=0;i<maxi;i++){
    if(height[i]>height[maxtmp]) maxtmp=i;
    else sum+=(height[maxtmp]-height[i]);
    // printf("(%d,%d)",sum,i);
}
maxtmp=heightSize-1;
for(i=heightSize-1;i>maxi;i--){
    if(height[i]>height[maxtmp]) maxtmp=i;
    else sum+=(height[maxtmp]-height[i]);
    // printf("(%d,%d)",sum,i);

}
return sum;
}