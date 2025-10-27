int trap(int* height, int heightSize){
    int i;
    int j,k;
    int count=0;
    for(i=0;i<heightSize;i++){
        //lh表示i左端最大的的值，rh表示i有段最大的值
        int lh=0,rh=0,h=0;
        //找到lh
        for(j=0;j<i;j++){
            if(lh<height[j]) lh=height[j];
        }
        //找到rh
        for(k=i+1;k<heightSize;k++){
            if(rh<height[k]) rh=height[k];
        }

        //当前i的高度height[i]若大于了lh或rh则此时没有水位(h==0)
        if(height[i]>=lh||height[i]>=rh){
            continue;
        } 
        if(lh>rh) h=rh;
        else h=lh;
        count+=h-height[i];        
    }
    
    return count;
}