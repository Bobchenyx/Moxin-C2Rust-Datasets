#define ADDBIT(x, n) ( (x) ^= ( 1 << (n) ) )
#define GETBIT(x, n) ( ( (x) >> (n) ) & 1 )
bool isUnique(char* astr){
    int flag = 0;
    while(*astr){
        ADDBIT(flag, *astr - 'a');
        if(!GETBIT(flag, *astr - 'a')){
            return false;
        }
        astr++;
    }
    return true;
}