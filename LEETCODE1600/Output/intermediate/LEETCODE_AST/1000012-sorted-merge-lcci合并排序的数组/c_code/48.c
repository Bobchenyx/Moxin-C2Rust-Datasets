void merge(int* A, int ASize, int m, int* B, int BSize, int n){
int pa=m,pb=0;
for(int i = 0; i < n; i++){
    A[pa]=B[pb];
    pa++;
    pb++;
}
for(int i = 0;i < ASize;i++){
    for(int j = i+ 1 ;j<ASize;j++){
        if(A[i]>A[j]){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
       
    }
}

}