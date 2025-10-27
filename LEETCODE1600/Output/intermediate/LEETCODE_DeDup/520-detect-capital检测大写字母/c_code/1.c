bool detectCapitalUse(char * word){
    int len;
    int i;
    bool firstCapital = false;
    bool secCapital = false;
    int whichCase;

    len = strlen(word);
    if(!len || len == 1) {
        return true;
    }
    if(word[0] >= 'A' && word[0] <= 'Z') {
        firstCapital = true;
    }

    if(word[1] >= 'A' && word[1] <= 'Z') {
        if(firstCapital) {
            whichCase = 1;
        } else {
            return false;
        }
    } else {
        if(firstCapital) {
            whichCase = 3;
        } else {
            whichCase = 2;
        }
    }

    for (i = 2; i < len; ++i) {
        switch(whichCase) {
            case 1:
                if(!(word[i] >= 'A' && word[i] <= 'Z'))
                    return false;
                break;
            case 2:
                if(!(word[i] >= 'a' && word[i] <= 'z'))
                    return false;
                break;
            case 3:
                if(!(word[i] >= 'a' && word[i] <= 'z'))
                        return false;
                break;
        }
    }

    return true;
}