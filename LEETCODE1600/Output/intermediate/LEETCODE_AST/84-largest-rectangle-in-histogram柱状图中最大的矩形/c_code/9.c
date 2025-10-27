int largestRectangleArea(int* heights, int heightsSize){
    int i,temp_area=0,temp_minh=0,max_area=0,j;

    for(i=0;i<heightsSize;i++){
        temp_minh = heights[i];
        for(j=i;j<heightsSize;j++){
            temp_minh = temp_minh < heights[j] ? temp_minh: heights[j];
            //printf("cyx temminh=%d i=%d j=%d \n",temp_minh,i,j);
            temp_area = temp_minh * (j-i+1);
            max_area = max_area > temp_area ? max_area : temp_area;
        }
    }
    return max_area;
}