int maxArea(int* height, int heightSize){
    int maxcontain = 0;
    if(heightSize==0) return 0;
    int i=0;
    int per=0,he = heightSize-1;
    while(per!=he)
    {
        int min = 0;
        if(height[per]>height[he]){
            min = height[he];
            int temp_count = (he-per)*min;
            if(temp_count > maxcontain)
            {
                maxcontain=temp_count;
            }
            he--;
        }
        else{

            min = height[per];
            int temp_count = (he-per)*min;
            if(temp_count > maxcontain)
            {
                maxcontain=temp_count;
            }
            per++;
        }
        
    }
    return maxcontain;
}