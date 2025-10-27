int romanToInt(char * s){
    int len = strlen(s);    //先获取字符串长度
    if(len == 0) return 0;
    int resultNumber = 0;//!!不要忘记初始化不然是一个随机数！！
    for(int i=0;i<len;i++){
          switch(s[i]){
              case 'I':resultNumber+=1;
                        if(i<(len-1))
                            if(s[i+1]=='V'||s[i+1]=='X') resultNumber-=2;                                            break;
              case 'V':resultNumber+=5; break;
              case 'X':resultNumber+=10;
                         if(i<(len-1))
                            if(s[i+1]=='L'||s[i+1]=='C') resultNumber-=20;                                           break;
              case 'L':resultNumber+=50;break;
              case 'C':resultNumber+=100;
                         if(i<(len-1))    
                            if(s[i+1]=='D'||s[i+1]=='M') resultNumber-=200;                                          break;
              case 'D':resultNumber+=500; break;
              case 'M':resultNumber+=1000;break;
              default: break;//不要丢了这一句；
          } 
    }
    return resultNumber;
  
    
}