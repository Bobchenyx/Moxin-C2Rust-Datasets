class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
vector<int> flag(seq.length(),0);
int sum=0;
int maxn=0;
int st;
int ed;
for(int i=0; i<seq.length(); i++){
    if(sum==0)
        st=i;
    if(seq[i]=='('){
        sum++;
        if(sum>maxn)
            maxn=sum;
    }
    if(seq[i]==')')
        sum--;
    if(sum==0){
        ed=i;
        int lv=maxn/2+1;
        maxn=0;
        int sumtmp=0;
        int flag1=0;
        for(int t=st; t<=ed; t++){
            if(sumtmp<=lv-1)
                flag1=0;
                if(seq[t]=='('){
                    sumtmp++;
                    if(sumtmp==lv&&flag1==0)
                        flag1=1;    
                }
                if(seq[t]==')')
                    sumtmp--;
                if(flag1==1)
                    flag[t]=1;
        }
    }    
}
return flag;
    }
};