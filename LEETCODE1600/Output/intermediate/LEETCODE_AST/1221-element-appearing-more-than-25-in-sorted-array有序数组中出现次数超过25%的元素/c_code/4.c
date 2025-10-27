int findSpecialInteger(int* arr, int arrSize){
        int n=arrSize/4+1;
        int i;
        int num;
        for(i=0;i<arrSize;i++){
            if(i==0)num=1;
            else if(arr[i]!=arr[i-1])num=1;
            else if(arr[i]==arr[i-1])num++;
            if(num>=n)return arr[i];
        }
        return ;
}