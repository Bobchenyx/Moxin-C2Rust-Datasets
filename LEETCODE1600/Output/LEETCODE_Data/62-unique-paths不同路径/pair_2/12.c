int uniquePaths(int m, int n){
    long int tmp1 = 1;
    long int tmp2 = 1;
    long int i = 0;

    if(m < 2 || n < 2){
        return 1;
    }
    if(m < n){
        for(i = 1; i < m ; ++ i){
            tmp1 *= i; 
        }
        for(i = 0; i < m - 1; ++ i){
            tmp2 *= (n + i);
        }

        return tmp2 / tmp1;
    }else{
        long int tmp = m;
        m = n;
        n = tmp;
        for(i = 1; i < m ; ++ i){
            tmp1 *= i; 
        }
        for(i = 0; i < m - 1; ++ i){
            tmp2 *= (n + i);
        }

        return tmp2 / tmp1;
    }

    
}