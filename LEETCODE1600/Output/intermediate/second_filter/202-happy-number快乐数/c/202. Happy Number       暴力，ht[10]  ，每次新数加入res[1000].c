bool isHappy(int n){
    int i = 0, j = 0, temp, sum, last;
    int ht[10] = {0};
    int res[1000] = {0};

    for (i = 0; i < 10; i++)
        ht[i] = i*i;
    
    temp = n;
    while (temp != 1) {
        for (i = 0; i < j; i++){
            if (res[i] == temp)
                return false;
        }
        if (i == j)
            res[j++] = temp;
        
        sum = 0;
        while (temp) {
            last = temp%10;
            sum += ht[last];
            temp = temp/10;
        }

        temp = sum;
    }
    return true;
}