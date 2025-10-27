char acRet[5101] = {'\0'};
char * addStrings(char * num1, char * num2)
{
    int iLenIdx1 = strlen(num1) - 1;
    int iLenIdx2 = strlen(num2) - 1;
    int iLen = 5099;
    int iCarry = 0;

    while((iLenIdx1>=0) || (iLenIdx2>=0) || (1==iCarry))
    {
        iCarry += (iLenIdx1>=0?num1[iLenIdx1]-'0':0) + (iLenIdx2>=0?num2[iLenIdx2]-'0':0);
        acRet[iLen] = iCarry%10 + '0';
        iCarry = iCarry/10;
        iLenIdx1--;
        iLenIdx2--;
        iLen--;
    }

    return &acRet[iLen+1];
}

/*char acRet[5101] = {'\0'};
char * addStrings(char * num1, char * num2)
{
    int iLenIndex1 = strlen(num1) - 1;
    int iLenIndex2 = strlen(num2) - 1;
    int iCarry = 0;
    int iLen = 5099;

    while((iLenIndex1>=0) || (iLenIndex2>=0) || iCarry==1)
    {
        iCarry += (iLenIndex1 >= 0 ? num1[iLenIndex1--] - '0': 0) + (iLenIndex2 >= 0 ? num2[iLenIndex2--] - '0' : 0);
        acRet[iLen--] = iCarry%10 + '0';
        iCarry /= 10;
    }
    return &acRet[iLen+1];
}*/