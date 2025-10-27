int removeDuplicates(int* nums, int numsSize){
    int i,j,k,temp=0,number=0,*a,sign=0;
    a=(int *)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++){
        a[i]=0;
    }
    for(i=0;i<numsSize;i++){
        number=nums[i];
        for(j=i+1;j<numsSize;j++){
            if(number==nums[j]){
                temp++;
                for(k=j+1;k<numsSize;k++){
                    a[k]=a[k]+1;
                }
            }
            else{
                continue;
            }
        }
    }
    for(i=0;i<numsSize;i++){
		number=nums[i];
		sign=0;
		for(j=i+1;j<numsSize;j++){
			if(number==nums[j]){
				sign++;
				if(sign>1){
					for(k=j+1;k<numsSize;k++){
						a[k]--;
					}
					sign--;
					temp--;
				}
			}
		}
	}
    for(k=0;k<numsSize;k++){
        nums[k-a[k]]=nums[k];
    }
    temp=numsSize-temp;
    return temp;
}