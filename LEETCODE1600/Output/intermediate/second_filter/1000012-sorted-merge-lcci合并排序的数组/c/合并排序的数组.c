void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int indexA=m-1,indexB=n-1;
    int cur=m+n-1;

    //因为题目是要求将B加入到A中，所以结束的标志是B全部排列完
    while(indexB>=0){
        //同时还要考虑到indexA比indexB先到-1
        if(indexA<0){
            A[cur]=B[indexB--];
        } else if(A[indexA]>=B[indexB]){
            A[cur]=A[indexA--];
        } 
        else {
            A[cur]=B[indexB--];
        }
        cur--;
    }


}