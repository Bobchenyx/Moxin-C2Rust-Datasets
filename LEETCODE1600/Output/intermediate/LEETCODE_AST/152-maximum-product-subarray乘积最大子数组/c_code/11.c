int max(int a,int b){
if(a>b) return a;
return b;}
int maxProduct(int* nums, int numsSize){
int i,j,k;
int flag=0; 
int Max,Min;
int MAX=nums[0];
for(i=1;i<numsSize;i++)
MAX=max(MAX,nums[i]);
int s[numsSize];
if(nums[0]<0) {flag=1;Min=0;Max=0;}
if(nums[0]==0) s[0]=0;
else s[0]=nums[0];
for(i=1;i<numsSize;i++)
{if(nums[i]==0){if(flag%2==0) MAX=max(MAX,s[i-1]);else {if(Max==0&&Min==i-1) MAX=max(MAX,nums[0]);else if(Max==0) MAX=max(MAX,s[i-1]/s[Min]);else if(Min==i-1) MAX=max(MAX,s[Max-1]);else MAX=max(MAX,max(s[Max-1],s[i-1]/s[Min]));}flag=0;s[i]=0;continue;}
if(nums[i]<0) {if(flag==0) Min=i;Max=i;flag++;}
if(s[i-1])s[i]=s[i-1]*nums[i];
else s[i]=nums[i];
}
if(flag%2==0) MAX=max(MAX,s[numsSize-1]);
else {if(Max==0&&Min==numsSize-1) MAX=max(MAX,nums[0]);else if(Max==0) MAX=max(MAX,s[numsSize-1]/s[Min]);else if(Min==numsSize-1) MAX=max(MAX,s[Max-1]);else MAX=max(MAX,max(s[Max-1],s[numsSize-1]/s[Min]));}
return MAX;
}