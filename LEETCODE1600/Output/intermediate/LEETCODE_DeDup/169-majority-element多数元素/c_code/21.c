typedef struct node{
    int *a;
    int *b;
    int table;
}Hash;

Hash* build(int n)
{
    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->a = (int*)malloc(sizeof(int)*n);
    h->b = (int*)malloc(sizeof(int)*n);
    h->table = n;
    for(int i=0; i<n; i++){
        h->b[i] = 0;
        h->a[i] = -999;
        }
    return h;
}

void insert(Hash* h,int x)
{
    int index = abs(x%h->table);
    while(h->b[index]!=0){
        if(h->a[index] == x){
            h->b[index]++;
            return ;
        }
        else{
            index = (index+1)%h->table;
        }
    }
    h->a[index] = x;
    h->b[index]++;   
}

int majorityElement(int* nums, int numsSize){
    int max;
    Hash* h = build(numsSize/2+1);
    for(int i=0;i<numsSize;i++)
        insert(h,nums[i]);
    for(int i=0;i<h->table;i++)
        if(h->b[i]>numsSize/2)
            max = h->a[i];
    return max;
}