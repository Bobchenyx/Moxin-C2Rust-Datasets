int maxArea(int* height, int heightSize){
    int max=0;
    for(int i=0;i<heightSize;i++){
        for(int j =i+1;j<heightSize;j++){
            int x = j-i;
            int y = height[j]>height[i]?
                    height[i]:height[j];
            if((x*y)>max)
                max = x*y;
        }
    }
    return max;
}

//第二种
//int maxArea(int* height, int heightSize){ --> --> -->
//  int max=0;
//    int l=0,r=heightSize-1;
//    while(l<r){
//        int x = r-l;
//        int y = height[l]>height[r]?
//                height[r]:height[l];
//        if((x*y)>max)
//            max = x*y;
//        if(y==height[l]) l++;
//        else r--;
//    }
//   return max;
//}