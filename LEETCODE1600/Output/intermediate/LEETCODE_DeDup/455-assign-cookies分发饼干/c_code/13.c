void sort(int* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High,temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&temp<Nums[j])--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&temp>Nums[i])++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        sort(Nums,Low,i-1);
        sort(Nums,i+1,High);
    }
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    sort(g,0,gSize-1);
    sort(s,0,sSize-1);
    int result=0,gIter=0,sIter=0;
    while(gIter<gSize&&sIter<sSize)
        if(g[gIter]<=s[sIter])
        {
            ++result;
            ++gIter;
            ++sIter;
        }
        else
            ++sIter;
    return result;
}