bool matchStar(int c, char * s, char * p);
bool isMatch(char * s, char * p){
    if (s[0] == '\0' && p[0] == '\0')
        return true;
    if (p[0] == '\0')
        return false;
    if (p[1] == '*')
        return matchStar(p[0], s, p+2);
    if (*s!='\0' && (p[0]=='.' || p[0]==*s))
        return isMatch(s+1,p+1);
    return false;
}
bool matchStar(int c, char * s, char * p){
    do {
        if (isMatch(s, p))
            return true;
    } while (*s != '\0' && (*s++ == c || c == '.'));   
    return false;    
}