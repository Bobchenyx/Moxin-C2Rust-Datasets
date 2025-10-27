#define HASH_SIZE (256)
#define GET_HASH_SUB(val) (val)

int longestPalindrome(char * s){
    int hash[HASH_SIZE];
    int notes[HASH_SIZE];
    int notesCnt = 0;
    int sub = 0;
    char *pChar = s;
    int len = 0;
    int flag = 0;

    if(NULL == s
        || 0 == strlen(s)){
        return 0;
    }

    memset(hash, 0, sizeof(hash));
    memset(notes, 0, sizeof(notes));
    while(*pChar != '\0'){
        sub = GET_HASH_SUB(*pChar);
        if(0 == hash[sub]++){
            notes[notesCnt] = sub;
            notesCnt++;
        }
        pChar++;
    }

    for(int i = 0; i < notesCnt; i++){
        sub = notes[i];
        if(0 == hash[sub] % 2){
            len += hash[sub];
        }else{
            len += hash[sub] - 1;
            flag = true;
        }
    }

    if(flag){
        len += 1;
    }

    return len;
}