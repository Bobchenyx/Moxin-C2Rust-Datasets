int largestRectangleArea(int* heights, int heightsSize){
    int max=0,sum=0,left=0,right=0;
    for(int i=0;i<heightsSize;i++){
        if(heights[i]!=0){ 
        sum=heights[i];
        for(int j=i-1;j>=0;j--){
            if(heights[j]>=heights[i]) sum+=heights[i];
            else break;
            if(heights[i]==heights[j]) heights[j]--;//春风不度玉门关
        }
        for(int k=i+1;k<heightsSize;k++){
            if(heights[k]>=heights[i]) sum+=heights[i];
            else break;
            if(heights[k]==heights[i]) heights[k]--;
        }
        if(sum>max) max=sum;
        }
    }
    return max;
}