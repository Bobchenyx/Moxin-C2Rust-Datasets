/* 位运算 */
char * toLowerCase(char * str){
    char *t = str;
    while(*t != '\0'){
        if(*t >= 'A' && *t <= 'Z')
            *t |= 0b00100000;
        t++;
    }
    return str;
}

// /* ASCII */
// char * toLowerCase(char * str){
//     char *t = str;
//     while(*t != '\0'){
//         if(*t >= 'A' && *t <= 'Z')
//             *t += 32;               // 'a' - 'A' == 0x20
//         t++;
//     }
//     return str;
// }