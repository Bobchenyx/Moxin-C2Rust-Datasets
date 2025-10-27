bool detectCapitalUse(char * word){

    bool firstUpper, othersUpper, othersLower;
    firstUpper = othersLower = othersUpper = false;
    if (word[0] >= 'A' && word[0] <= 'Z')
        firstUpper = true;
    for (int i = 1; word[i]; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            othersUpper = true;
            break;
        }
    }
    for (int i = 1; word[i]; ++i) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            othersLower = true;
            break;
        }
    }
    if (firstUpper && othersUpper && othersLower)
        return false;
    if (!firstUpper && othersUpper)
        return false;
    return true;
}