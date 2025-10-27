double myPow(double x, int n){
        if(x==0||x==1||n==1)
        return x;

        if(n==0)
            return 1;
        if(n<0)
            return 1/(myPow(x,-(n+1))*x);
        else
            {
                double s=myPow(x,n/2);
                if(n%2==0)   
                    return s*s;
                else
                    return s*s*x;
            }
 }