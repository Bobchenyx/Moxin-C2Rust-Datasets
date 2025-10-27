bool isOK(int i,int j,int k);
int movingCount(int m, int n, int k){
    int count=1;
    int tmp[m][n];
    memset(tmp,0,sizeof(tmp));
    tmp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isOK(i,j,k)){
                if(((i-1>=0)&&(tmp[i-1][j]==1))||((j-1>=0)&&(tmp[i][j-1]==1))){
                    tmp[i][j]=1;
                    count++;
                }
            }
        }
    }
    return count;
}

bool isOK(int i,int j,int k){
     int int_i=i/100+(i%100)/10+(i%10);
     int int_j=j/100+(j%100)/10+(j%10);
     return (int_i+int_j>k?false:true);
}