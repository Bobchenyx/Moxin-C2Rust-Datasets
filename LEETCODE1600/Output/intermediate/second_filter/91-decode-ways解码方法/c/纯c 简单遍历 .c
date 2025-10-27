int numDecodings(char * s){
    int scnt = strlen(s);
    int *dp = (int *)malloc((scnt +1) *sizeof(int));
  
    int cur;
    int pre;
   
    // 头上是0
    if(s[0] == '0'){
        return 0;
    }
    if(scnt == 1){       
            return 1;        
        
    }
    
    
     dp[0] = 1;
     dp[1] = 1;
   
  
    for(int i = 2; i<= scnt; i++){
        cur = (s[i-1] -'0');
        pre = (s[i -2] -'0');
        
        //  连续的0 或者 0前面>=3
        if((cur == 0) &&( (pre >=3) || (pre == 0))){
            return 0;
        }

        if(cur == 0) {
            // 新增 的字符只能和前面的一起编码: dp[i] = dp[i-2];
            dp[i] = dp[i-2];
        } else if((pre == 0)){
            // 新增的字符只能单独编码: dp[i] = dp[i-1];
            dp[i] = dp[i-1];
        } else {
             if((cur + pre*10)<=26 ){
                //  新增的字符既可以和前面的一起编码又可以独立编码: dp[i] = dp[i-1] + dp[i-2];
                dp[i] = dp[i-2] + dp[i-1];
                } else {
                    // 新增的字符只能单独编码: dp[i] = dp[i-1];
                    dp[i] = dp[i-1];
                }
        }

       

    }    

    return dp[scnt];
}