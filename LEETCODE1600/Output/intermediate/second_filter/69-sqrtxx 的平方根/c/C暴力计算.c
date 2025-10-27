int mySqrt(int x){
    if(x<=1) return x;
    int i=x/2;  
    int j; 
    for(j=1;j<=46339;j++)
    {
        if(j*j==x) 
        {
            break;
            return j;
            
        }
        if(j*j<x&&(j+1)*(j+1)>x) 
        {
            break;
            return j; 
            
        }
    }

    return j;

}