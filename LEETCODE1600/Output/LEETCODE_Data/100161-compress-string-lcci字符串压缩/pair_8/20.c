#include<math.h>
char* compressString(char* S){
    int length = 0;
    int a_length = 0;
    int b_length = 0;
    char* a = S;
    int* c = NULL;
    while(*a) 
    {
        length++;
        a++;
    }
    char* b = (char*)malloc(500000*(sizeof(char))); //500000是因为有一个50000没通过，应该是b最后的长度超过了，emm，那应该给2*50000就行，这个有点大了。
    //printf("%d\n",length);
    a = S;
    while(*a)
    {
        if(a == S || *a == *(a-1) )     //用来对多个重复的字符计数
        {
            if(*a == *(a+1) && a != S + length) a_length ++;
            else
            {
                a_length++;
                *b = *a;
                b++;
                if(a_length >= 1000)   //以下的所有if-else都是a_length的字符表示
                {
                    int c = a_length / 1000;
                    int d = a_length % 1000 / 100;
                    int e = a_length % 1000 % 100 / 10;
                    int f = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    *b = '0' + e;
                    b++;
                    *b = '0' + f;
                    b++;
                    b_length += 5;
                }
                else if(a_length >= 100)
                {
                    int c = a_length / 100;
                    int d = a_length % 100 /10;
                    int e = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    *b = '0' + e;
                    b++;
                    b_length += 4;
                }
                else if(a_length >= 10)
                {
                    int c = a_length / 10;
                    int d = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    b_length += 3;
                }
                else
                {
                    *b = '0' + a_length;
                    b++;
                    b_length += 2;
                }
            }
        }
        else if(*a != *(a-1) && *a != *(a+1))   //这是对只出现了一次的字符的计数
        {
            a_length = 1;
            *b = *a;
            b++;
            *b = '0' + a_length;
            b++;
            b_length += 2;
        }
        else a_length = 1;      //这是对多次出现字符的第一次计数
        //printf("第%d个出现了%d次\n",a-S,a_length);
        a++;
    }
    *b = '\0';
    if(b_length >= length)return S;     //判断b还是原字符长
    else return b - b_length;
}