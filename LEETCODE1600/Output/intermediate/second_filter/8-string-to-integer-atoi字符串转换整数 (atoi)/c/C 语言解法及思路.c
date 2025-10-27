int myAtoi(char * str){
    int index;
    int sum = 0;
    int sign = -1;              // -1 代表 + ，1 代表 -
    int overflow = 0;          // 1 代表越界
    int temp;
    int boundary = INT_MAX;

    index = First_char_index(str);
    if (Is_str_invalid(str, index))
        return 0;

    temp = Get_char(str, index);
    if (temp == -1) {
        sign = 1;
        temp = Get_char(str, ++index);
        boundary = INT_MIN;
    } else if (temp == 10)
        temp = Get_char(str, ++index);

    while (temp >= 0 && temp < 10) {
        if ( sum * sign < sign * boundary / 10 ) {
            overflow = 1;
            break;
        }
        sum *= 10;
        
        if ( sum * sign < boundary * sign + temp ) {
            overflow = 1;
            break;
        }
        sum -= sign * temp;

        temp = Get_char(str, ++index);
    }

    if (overflow) {
        if (sign == -1)
            return INT_MAX;
        else
            return INT_MIN;
    } else 
        return sum;
}

int First_char_index(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') 
            i++;
        else
            break;
    }

    if (str[i] == '\0')
        return -1;
    else
        return i;
}

int Get_char(char *str, int index)
{
    switch (str[index]) {
    case '0':
            return 0;
    case '1':
            return 1;
    case '2':
            return 2;
    case '3':
            return 3;
    case '4':
            return 4;
    case '5':
            return 5;
    case '6':
            return 6;
    case '7':
            return 7;
    case '8':
            return 8;
    case '9':
            return 9;
    case '+':
            return 10;
    case '-':
            return -1;
    default:
            return -2;
    }
}

int Is_str_invalid(char *str, int index)
{
    if (index == -1)
        return 1;
    else if (Get_char(str, index) == -2)
        return 1;
    else
        return 0;
}