void gameOfLife(int** board, int boardSize, int* boardColSize){
    int* row;
    row = (int*)malloc(*boardColSize*sizeof(int));
    int i,j,num,old;
    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
            num = 0;
            if(i>0){
                num += *(row+j);
                if(j>0) num += old;
                if(j<*boardColSize-1) num += *(row+j+1);
            } 
            if(i<boardSize-1){
                num += *(*(board+i+1)+j);
                if(j>0) num += *(*(board+i+1)+j-1);
                if(j<*boardColSize-1) num += *(*(board+i+1)+j+1);
            }
            if(j>0) num += *(row+j-1);
            if(j<*boardColSize-1) num += *(*(board+i)+j+1);
            old = *(row+j);                //更新old
            *(row+j) = *(*(board+i)+j);    //更新上一行数据row
            if(*(*(board+i)+j)==0){
                if(num==3) *(*(board+i)+j) = 1;
            }
            else{
                if(num<2||num>3) *(*(board+i)+j) = 0;
            }
        }
    }
}