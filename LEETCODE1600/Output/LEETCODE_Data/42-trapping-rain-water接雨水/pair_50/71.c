int MIN(int a,int b){return  a>b?b:a;}
int trap(int* height, int heightSize){
	int s[100005];  //模拟栈 
	int top=-1; 
	int sum = 0,h,c;
	for(int i=0;i<heightSize;i++){
		while(top>-1&&height[i]>height[s[top]]){
			c = s[top];
			if((--top)==-1) break;  //栈空结束 
			h = MIN(height[s[top]]-height[c],height[i]-height[c]);
			sum+=(h*(i-s[top]-1));
		}
		s[++top]=i;
	} 
	return sum;
}