int calculateInner(char * s, int* Pos){
    int pos = *Pos;
    char* currentChar = s;
    int result = 0;
    int flag = 1;
    int tempNum = 0;

    while (*(s + pos) != '\0') {
        currentChar = s + pos;

        if (*currentChar == ' ') {
            pos++;
            continue;
        } else if (isdigit(*currentChar)) {
            tempNum = 0;
            while(isdigit(*currentChar)) {
                tempNum = tempNum * 10 + (*currentChar - '0');
                pos++;
                currentChar = s + pos;
            }
            result = result + (flag * tempNum);
            continue;
        } else if (*currentChar == '+') {
            flag = 1;
            pos++;
            continue;
        } else if (*currentChar == '-') {
           // printf("- get flag = %d \n", flag);
            flag = -1;
            pos++;
            continue;
        } else if (*currentChar == '(') {
            *Pos = pos + 1;
            tempNum = calculateInner(s, Pos);
            result = result + (flag * tempNum);
            pos = *Pos;
        } else if (*currentChar == ')') {
            *Pos = pos + 1;
            return result;
        }
    }

    return result;
}

int calculate(char* s)
{
    int pos = 0;
    return calculateInner(s, &pos);
}