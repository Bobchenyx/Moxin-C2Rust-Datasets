#include<stdio.h>
#define ROM_MAX 1000    //罗马字母表示的最大值

int romanToInt(char * s)
{
    short hash[26] = {0};
    hash['I' - 'A'] = 1;
    hash['V' - 'A'] = 5;
    hash['X' - 'A'] = 10;
    hash['L' - 'A'] = 50;
    hash['C' - 'A'] = 100;
    hash['D' - 'A'] = 500;
    hash['M' - 'A'] = 1000;
    short num = 0, pre = ROM_MAX;
    for (int i = 0; s[i] != '\0' ; i++)
    {
        short index = s[i] - 'A';
        if (hash[index] > pre)  //如果后一个字母比前一个大，要进行处理
        {
            num = num - pre * 2;
        }
        pre = hash[index];
        num += hash[index];
    }
    return num;
}