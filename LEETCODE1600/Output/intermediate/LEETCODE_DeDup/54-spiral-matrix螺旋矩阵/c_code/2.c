int min(int a,int b) {
	if(a>=b) return b;
	else return a;
}//用C语言就得有造轮子的觉悟，为了确定层数
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	* returnSize=0;
	int r=matrixSize,c=* matrixColSize;
    if(matrix==NULL || r==0) return matrix;
	int sum=matrixSize*(*matrixColSize);
    int* ret=(int*)calloc(sum+1,sizeof(int));
	int ceng=min(r,c);
	if(ceng%2==0) ceng=ceng/2;
	else ceng=ceng/2+1;//确定层数的时候分奇偶
	int i;//当前层数
	int h,l;//汉语拼音 行 列，之前r c已经用过了
	for(i=0; i<ceng; i++) {//整个转一圈，我得判断里加了个(* returnSize)<sum，这样省的越界。一圈一圈。
		h=i,l=i;
		while((l<c-i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h][l++];
		}
		h++;
		l--;
		while((h<r-i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h++][l];
		}
		l--;
		h--;
		while((l>i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h][l--];
		}
		while((h>i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h--][l];
		}
	}
	ret[* returnSize]='\0';
	return ret;

}