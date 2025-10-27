int findMax(int* arr,int len);  //查找数组中的最大元素，返回其索引

int trap(int* height, int heightSize){
    if(heightSize==0)return 0;

    int *tmp=(int*)calloc(heightSize,sizeof(int));
    int k=0;
    int count=0;
    //以tmp首部tmp[0]为最大值，在height中找到大于等于tmp[0]的值，
    //取出这一段区域，然后用tmp[0]逐个减去tmp里面的元素，得到这块区域的储水量
    for(int i=0;i<heightSize;i++){  
        if(height[i]>=tmp[0]){
            for(int j=0;j<=k;j++){
                count+=(tmp[0]-tmp[j]);
            }
            k=0;        //找到一段完整的储水区之后更新储水区域的头部
            tmp[k]=height[i];
        }else {
            tmp[++k]=height[i];  //没有找到储水区域的尾部，则将该小区域先并入储水区域
        }
    }
    //如果最后找到了一段封闭的储水区域，直接返回
    if(k==0){
        free(tmp);
        return count;
    }
    //否则将最后保存的tmp所在的储水区域的最大值替换为第二大的值，
    //然后可以用上述for循环中的方法，计算完整的储水区域，这里使用递归来完成后面的操作
    tmp[0]=0;
    tmp[0]=tmp[findMax(tmp,k)];
    return (count+trap(tmp,k+1));
}

int findMax(int* arr,int len){
    int index=0;
    for(int i=0;i<=len;i++){
        if(arr[i]>arr[index]){
            index=i;
        }
    }
    return index;
}