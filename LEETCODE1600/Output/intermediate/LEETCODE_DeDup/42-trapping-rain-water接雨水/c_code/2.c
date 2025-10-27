void findTrap(int* height,int heightSize,int* ret,int index){
    if(heightSize == 0){
        return;
    }
    int left = heightSize,right = 0;
    int *head = height;
    for(int i=0;i<heightSize;i++){
        if(height[i] < index){
            (*ret)++;
        }
        if(height[i] > index){
            left = i<left?i:left;
        }
        if(height[i] > index){
            right = i>right?i:right;
        }
    }
    if(left < right){
        head = head + left;
        findTrap(head,right-left+1,ret,index+1);
    }else{
        return;
    }
}
int trap(int* height, int heightSize){
    int ret =0;
    findTrap(height,heightSize,&ret,0);
    return ret;
}