bool dtsMatch(char *s, char *p, int sflag, int pflag) {
    if (pflag < 0) {
        if (sflag < 0) {
            return true;
        }
        return false;
    }
    if (sflag < 0) {
        if (pflag == 0) {
            return false;
        }
        //pflag >= 1
        if (p[pflag] != '*') {
            return false;
        }
        // mX* =  m
        return dtsMatch(s, p, sflag, pflag - 2);
    }
    // sflag >= 0, pflag >= 0    
    if (s[sflag] == p[pflag]) {
        return dtsMatch(s, p, sflag - 1, pflag - 1);
    }
    if (p[pflag] == '.') {
        return dtsMatch(s, p, sflag - 1, pflag - 1);
    }
    if (p[pflag] == '*') {
        //match zero
        if (dtsMatch(s, p, sflag, pflag - 2)) {
            return true;
        }
        // must match 1 or more
        if (p[pflag - 1] == '.' || p[pflag - 1] == s[sflag]) {
            // match 1
            if (dtsMatch(s, p, sflag - 1, pflag - 2)) {
                return true ;
            }
            // match more
            return dtsMatch(s, p, sflag - 1, pflag);
        }
        return false;        
    }
    return false;
    
}
bool isMatch(char * s, char * p) {
    int slen = strlen(s);
    int plen = strlen(p);
    //printf("dtsmatch %d,%d\n", slen,plen);
    return dtsMatch(s, p, slen - 1, plen - 1);
}