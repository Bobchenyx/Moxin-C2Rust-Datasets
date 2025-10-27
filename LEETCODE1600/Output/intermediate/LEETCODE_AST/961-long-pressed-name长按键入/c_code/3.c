bool isLongPressedName(char * name, char * typed){
    int length1=strlen(name),length2=strlen(typed);
    int i=0,j=0;
    while(i<length1||j<length2)
    {
        if(name[i]!=typed[j])
        {
            if(i==0)
            return false;
            if(typed[j]==name[i-1])
            j++;
            else 
            return false;
        }
        else{
            i++;j++;
        }
    }
    if(i==length1&&j==length2)
    return true;
    return false;
}