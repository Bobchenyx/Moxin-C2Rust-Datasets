void merge(int* A, int ASize, int m, int* B, int BSize, int n){

    int i = 0;//记录上次插入的位置
    int j = 0;//记录剩下的

    int newSize = m;
    while(j<n && i<newSize){
            if (B[j] >= A[i])//
                i++;
            else{//pos后面的往后移动一个
                for(int k = newSize -1;k>=i;k--)
                {
                    A[k+1] = A[k];
                }
                A[i] = B[j];//插入到pos位置，B向后移动
                j++;
                newSize++;

            }
     }//end while
     // 将剩下的移动到数组后面
     for(int k = j;k< BSize;k++)
     {
        A[newSize] = B[k];
        newSize++;
     }
}