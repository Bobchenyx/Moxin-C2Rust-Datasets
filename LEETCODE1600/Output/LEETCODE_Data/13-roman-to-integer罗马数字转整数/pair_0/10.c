int read(char a){
    switch (a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  printf("Input Error!\n");
                  return 0;
    }
}

int romantoint(char *s){
    int len = 0;
    int pos = 0;
    int sum = 0;
    int next = 0;
    for(len = 0;s[len]!='\0';len++);
    while(pos != len){
        printf("pos:%d\n",pos);
        if(s[pos+1] != '\0'){
            if(read(s[pos+1])>read(s[pos])){
                next = read(s[pos+1])-read(s[pos]);
                pos += 2;
                sum += next;
                continue;
            }
        }
        next = read(s[pos]);
        pos ++;
        sum += next;
    }
    return sum;
}