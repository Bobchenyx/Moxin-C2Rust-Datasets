int minFlips(int a, int b, int c){
    if ((a|b)==c)
        return 0;
    int a_binary,b_binary,c_binary,i,count=0;
    i = 30;
    while(i>=0){
        a_binary = ((a&(1<<i))>>i);
        b_binary = (b&(1<<i))>>i;
        c_binary = (c&(1<<i))>>i;
        if ((a_binary|b_binary)!=c_binary){
            if (c_binary==1)
                count++;
            else{
                if (a_binary)
                    count++;
                if (b_binary)
                    count++;
            }
        }
        i--;
    }
    return count;
}