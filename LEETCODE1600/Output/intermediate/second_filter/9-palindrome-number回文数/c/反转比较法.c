bool isPalindrome(int x)
{
    int i,temp=0,sign=x,number=x;;
    long sum=0;
    int *a;
    if(x<0)return false;
    else if(x==0)return true;
    while(number!=0){           //该循环获取当前给定数的位数
        number=number/10;
        temp++;
    }
    a=(int *)malloc(temp*sizeof(int));//确定给定数值的位数后，为每一位动态分配内存
    for(i=temp-1;i>=0;i--){  //该循环将数值的最低位放入到最高位，倒序存放
        a[i]=sign%10;
        sign=sign/10;
    }
    for(i=0;i<temp;i++){
        sum=sum+a[i]*pow(10,i);
    }
    if(sum==x)
        return sum;
    else
        return false;
}