bool isLongPressedName(char * name, char * typed){
    char last_ch;
    while(*name)
    {
        if(*name == '\0')
        {
            while(*typed != '\0')
            {
                if(*typed != last_ch)
                    return false;
            }
        }

        if(*typed != *name)
        {
            if(*typed != last_ch)
                return false;
            typed++;
        }
        else
        {
            last_ch = *name;
            name++;
            typed++;
        }
    }
    
    return true;
}