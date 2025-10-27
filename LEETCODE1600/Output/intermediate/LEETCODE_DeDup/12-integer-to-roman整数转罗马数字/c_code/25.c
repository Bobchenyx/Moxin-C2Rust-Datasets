#include<string.h>
char *romanBaseValue(int m) {
    switch (m) {
        case 1: {
            return "I";
        } break;
        case 5: {
            return "V";
        } break;
        case 10: {
            return "X";
        } break;
        case 50: {
            return "L";
        } break;
        case 100: {
            return "C";
        } break;
        case 500: {
            return "D";
        } break;
        case 1000: {
            return "M";
        } break;
            
        case 4: {
            return "IV";
        } break;
        case 9: {
            return "IX";
        } break;
          
        case 40: {
            return "XL";
        } break;
        case 90: {
            return "XC";
        } break;
         
        case 400: {
            return "CD";
        }break;
        case 900: {
            return "CM";
        }
            
        default:
          return "ERROR";
            break;
    }
}


char * intToRoman(int n){
    int romanValues[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *ret = calloc(sizeof(char), 20);
    for (int i = 0 ; i < 13 ; i++) {
        int count = 0;
        while (n >= romanValues[i]) {
            n = n - romanValues[i];
            count++;
        }
        for (int j = 0 ; j < count; j++) {
            char *roman = romanBaseValue(romanValues[i]);
            strcat(ret, roman);
        }
    }
    return ret;
    
}