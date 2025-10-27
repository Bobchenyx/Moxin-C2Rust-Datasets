int get_digit_sum(int a,int b){
	int sum=0;
	while(a!=0){
		sum+=a%10;
		a/=10;
	}
	while(b!=0){
		sum+=b%10;
		b/=10;
	}
	return sum;
}
int movingCount(int m, int n, int k){
	//maximum of row+col
	int MAX=m+n-2;
//	//smaller one of m&n
//	int SMALL;
	int count=0;
	//if this diag accessible
	int flag=1;
	int sum=0;
	if(m>n){
		int row,startRow=0;
//		SMALL=n; 
		//diag move
		while(flag==1&&sum<=MAX){
			flag=0;
			row=startRow;
			//move along the diag
			while(row<m&&row<=sum){
				if(get_digit_sum(row,sum-row)<=k){
					flag=1;
					count++;
				}
				row++;
			}
//			if(++sum>=SMALL)startRow++;
			if(++sum>=n)startRow++;
		}
	} 
	else{
		int col,startCol=0;
//		SMALL=n; 
		//diag move
		while(flag==1&&sum<=MAX){
			flag=0;
			col=startCol;
			//move along the diag
			while(col<n&&col<=sum){
				if(get_digit_sum(col,sum-col)<=k){
					flag=1;
					count++;
				}
				col++;
			}
//			if(++sum>=SMALL)startRow++;
			if(++sum>=m)startCol++;
		}
	}
	return count;
}