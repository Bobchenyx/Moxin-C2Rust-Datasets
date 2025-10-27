char * toLowerCase(char * str){
    char *new=str;
    while(*str){if(*str>0x40&&*str<0x5B)*str+=0x20;str++;}
    return new;
}