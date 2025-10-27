int top = 0;//用来记录有几种情况
void parentheses(int *nums,char **rear, int n,int less,int max)
{
    if( n < max ){
    	int less1=less;//less是被传递来的，不可改变，需用来限制nums[n]的上限
        while( nums[n] <= n-(max-less) ){//这里是nums[n]可达到的最大值，如果less=max，最大值为n也就是当前位置
            parentheses(nums,rear,n+1,less1,max);
            nums[n]++;
            less1--;
        }
        nums[n] = 0;
    }
    if( n == max ){
        rear[top] = (char *)malloc((max*2+1)*sizeof(char));
        int i=0,j=0,l=0;
        nums[n] = less;//最后一个左括号后面的右括号为less个
        for( i=1; i<=max; i++ ){
            rear[top][j++] = '(';
            while( l < nums[i] ){
                rear[top][j++] = ')';
                l++;
            }
            l = 0;
        }
        rear[top][j] = '\0';
        top++;
    }

}

char ** generateParenthesis(int n, int* returnSize){
    top = 0;
    int i=0,sum=1;
    for( i=1; i<=n; i++ ) sum *= i;
    int *nums = (int *)calloc((n+1),sizeof(int));//这里的nums[0]未被使用，为了方便表示只用1-n
    char **rear = (char **)malloc(sum*sizeof(char *));
    parentheses(nums,rear,1,n,n);
    *returnSize = top;
    return rear;
}