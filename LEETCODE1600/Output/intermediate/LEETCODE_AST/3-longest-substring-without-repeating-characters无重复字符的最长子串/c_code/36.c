#include <string.h>
int lengthOfLongestSubstring(char * s){
    //使用类似桶排序方式计数
    int counter[128];
    //归零
    memset(counter, 0, sizeof(counter));
    int maxLength=0;
    int length=0;
    int start=0,end=0;
    int ascii;
    while(s[start] != '\0'){
        //end到达结尾
        if(s[end]=='\0'){
            start++;
            //归零
            memset(counter, 0, sizeof(counter));
            if(maxLength<length)    maxLength=length;
        }else{
            ascii = (int)s[end++];
            if(++counter[ascii]==2){
                //printf("start:%d\t,end:%d\t,lenght:%d\n",start,end,length);
                start++;
                end=start;
                if(maxLength<length)    maxLength=length;
                //归零
                length=0;
                memset(counter, 0, sizeof(counter));
            }else{
                length++;
            }
        }   
    }
    return maxLength;
}