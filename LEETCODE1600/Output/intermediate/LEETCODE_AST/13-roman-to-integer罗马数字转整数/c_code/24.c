/*
定义七种字符表示的含义，之后根据输入，依次判断，
若i大于i+1，则直接取该值加入sum中
若i小于i+1，则使用i+1的值减去i的值加入sum中
*/
int getnum(char a){
    switch(a){
        case 'I':
            return 1;
            //break;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char * s){
    int i,a,b,n,sum=0;
    while(s[i]){
        i++;
        n++;
    }//为什么每次不能直接用s[i]来作为判断，而非要加上数s的个数的这段代码。

    for(i=0;i<n-1;i++){
        a=getnum(s[i]);
        b=getnum(s[i+1]);
        if(a==0 || b==0)
            return 0;
        if(a>=b)
            sum+=a;
        else{
            sum+=(b-a);
            if(i<n-1)
                i++;
            else
                break;
        }
    }

    if(i<n){
        a=getnum(s[i]);
        sum+=a;
    }

    return sum;
}