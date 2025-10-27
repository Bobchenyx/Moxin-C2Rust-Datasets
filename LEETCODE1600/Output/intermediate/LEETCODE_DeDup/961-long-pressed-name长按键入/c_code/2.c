bool isLongPressedName(char * name, char * typed){
    int i=0,j=0,c1,c2;
   while(name[i]!='\0'&&typed[j]!='\0')
    {
        c1=0;
        c2=0;
        while(name[i]==name[i+1])
        {
            c1++;
            i++;
        }
        while(typed[j]==typed[j+1])
        {
            c2++;
            j++;
        }
        if(typed[j]==name[i]&&c2>=c1)
        {
            i++;
            j++;
        }
        else
        {
            return false;
        }
    }
    if(name[i]!='\0')
        return false;
    return true;
}