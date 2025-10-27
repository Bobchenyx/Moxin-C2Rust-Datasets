bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
   int flag = 0;

   if(matrixSize == 0 || *matrixColSize == 0) return flag;

   int colsize = *matrixColSize;
   int i,j;
   


   for(i = matrixSize-1;i >= 0;i--){
       if(target >= matrix[i][0]){
           for(j = 0;j < colsize;j++){
               if(target == matrix[i][j]){
                   flag = 1;
               }
           }
       }
   }

   return flag;
}