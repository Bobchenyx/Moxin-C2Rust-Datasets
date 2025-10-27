int Min(int a, int b){
    return (a<b)?a:b;
}
int trap(int* height, int heightSize){
    if(heightSize == 0)
        return 0;
    /*这里用一个单调栈，但存储的内容并不是height数组的值，而是对应height数组的值的下标*/
    /*因为用单调栈可以轻松求到左右两边的边界高度，但又要同时保存左右两边的宽度，所以用height数组的元素的下标入栈最合适*/
    int *stack=(int*)malloc(sizeof(int)*heightSize);
    int topIndex=-1;
    int sum=0;
    for(int i=0; i<heightSize; i++){
        while(topIndex >= 0 && height[i]>height[stack[topIndex]]){
            /*此时保存的topTemp为要计算的面积的底，因为要横向计算，所以最后计算的水面高度要减去height[topTemp]*/
            int topTemp=stack[topIndex];
            topIndex--;
            /*若有相同的栈顶元素，则全部出栈；注意此处是高度相同，而不是同一个下标值*/
            while(topIndex >= 0 && height[stack[topIndex]]==height[topTemp]){
                topIndex--;
            }
            if(topIndex >= 0){
                int topKeep=stack[topIndex];
                /*这里用topKeep来保存左边界的下标值，而右边界的下标值就是i，此时宽度为 i-topKeep-1 */
                /*左边界的高度为stack栈顶保存到height数组值，即height[stack[topIndex]];右边界高度为height[i]*/
                sum+=(Min(height[stack[topIndex]], height[i])-height[topTemp])*(i-topKeep-1);
            }
        }
        stack[++topIndex]=i;
    }
    return sum;
}