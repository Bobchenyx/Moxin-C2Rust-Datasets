int cmp(const void *a,const void *b){
    if(*(int *)a>0&&*(int *)b<0)
        return 1;
    if(*(int *)a<0&&*(int *)b>0)
        return -1;
    return *(int *)a-*(int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    if(ASize==1||ASize==0)
        return 0;

    qsort(A,ASize,sizeof(int),cmp);
    
    int i=0,j=1,result=0;
    int *temp=(int *)malloc(sizeof(int)*ASize);
    int rear=0,front=0;
    int x=0;
    while(j<ASize){
        int gap=A[j]-A[i];
        switch(gap){
            case 0:         //元素重复，入队
                temp[rear++]=A[j++];
                break;            
            default:        //有多余空位，填入之前重复的元素
                x=1;
                while(gap-1>=x&&front!=rear){
                    result=result+x+A[i]-temp[front++];
                    x++;
                }
                i=j++;
        }

    }
        x=1;        //遍历结束之后，将对内还有的元素，填入数组之后
        while(front!=rear){
            result=result+x+A[ASize-1]-temp[front++];
            x++;
        }
        return result;
}