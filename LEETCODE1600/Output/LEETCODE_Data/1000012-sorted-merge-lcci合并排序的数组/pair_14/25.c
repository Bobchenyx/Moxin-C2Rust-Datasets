void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int* C;
    C = (int *)malloc(ASize*sizeof(int));
    int i=0,j=0,k=0;
    int label;
    label = m+n;
    int diff;
    if(n>0){
        for(label;label>0;label--){
            if(i<m && j<n){
                diff = *(A+i) - *(B+j);
                if(diff<0){
                    *(C+k) = *(A+i);
                    i++;
                    k++;
                }else if(diff>=0){
                    *(C+k) = *(B+j);
                    j++;
                    k++;
                }
            }else if(i>=m && j<n){
                *(C+k) = *(B+j);
                j++;
                k++;
            }else if(i<m && j>=n){
                *(C+k) = *(A+i);
                i++;
                k++;
            }
        }
        for(i=0;i<(m+n);i++){
            *(A+i) = *(C+i);
        }
    }else{}
}