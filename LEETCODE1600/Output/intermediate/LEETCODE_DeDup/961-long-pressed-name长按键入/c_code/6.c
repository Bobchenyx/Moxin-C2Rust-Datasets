bool isLongPressedName(char * name, char * typed){
    int name_index=0,typed_index=0;
    while(name[name_index]!=0){
        if(name[name_index+1]!=name[name_index]){
            if(typed[typed_index]!=name[name_index]) return 0;
            while(typed[typed_index+1]==name[name_index]) typed_index++;
        }
        else if(typed[typed_index]!=name[name_index]) return 0;
        typed_index++;
        name_index++;
    }
    return 1;
}