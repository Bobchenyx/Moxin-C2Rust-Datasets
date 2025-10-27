bool isUnique(char* astr){
    bool isUnique;
    int length = strlen(astr);
    int flo[128] = {0};
    for(int i = 0;i < length;++i)
    {
        flo[astr[i]]++;
        if(flo[astr[i]] > 1)
        {
            isUnique = false;
            break;
        }
        if(i == length - 1)
        {
            isUnique = true;
        }
    }
    // for(int i = 0;i < 128;++i)
    // {
    //     if(flo[i] > 1)
    //     {
    //         isUnique = false;
    //         break;
    //     }
    //     if(i == 127)
    //     {
    //         isUnique = true;
    //     }
    // }
    return isUnique;
}