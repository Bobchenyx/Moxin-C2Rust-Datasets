int numberOfSteps (int num){
    int f = 0;
    printf("%d ", num);
    if(num == 0)
    {
        f = 0;
    }
    else if(num %2 == 0)
    {
        f = numberOfSteps(num/2)+1;
    }
    else
    {
        num = num-1;
        f = +1;
        f = numberOfSteps(num)+1;
    }
    return f;
}