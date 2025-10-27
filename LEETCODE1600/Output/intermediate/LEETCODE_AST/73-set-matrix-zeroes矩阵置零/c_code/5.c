void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int i,j;
    int irow=matrixSize;//行
    int icol=matrixColSize[0];//列
	int *m,*n;//辅助矩阵
    m=malloc(irow*sizeof(int));//行辅助数组
    n=malloc(icol*sizeof(int));//列辅助数组
	for(i=0;i<irow;i++){//m[]初始化
		m[i]=0;
	}
	for(i=0;i<icol;i++){//n[]初始化
		n[i]=0;
	}
	for(i=0;i<irow;i++){//操作辅助数组，如果matrix的值为0，将其对应的行列数组的值置1
		for(j=0;j<icol;j++){
			if(matrix[i][j]==0){
				m[i]=1;
				n[j]=1;
			}
		}
	}
	for(i=0;i<irow;i++){//遍历行辅助数组，将matrix数组值为0的数整行置0
		if(m[i]==1){
			for(j=0;j<icol;j++){
				matrix[i][j]=0;
			}
		}
	}
	for(i=0;i<icol;i++){//遍历列辅助数组，将matrix数组值为0的数整列置0
		if(n[i]==1){
			for(j=0;j<irow;j++){
				matrix[j][i]=0;
			}
		}
	}
}