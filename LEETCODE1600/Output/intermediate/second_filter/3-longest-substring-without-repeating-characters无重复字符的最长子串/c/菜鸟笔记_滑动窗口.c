char gHashTable[256];

bool isDuplicated(char* ch){//如果已经有相同的字符了，那么会返回true
       if (gHashTable[*ch]){
           return true;
       }
       else{
           return false;
       }
   }
int lengthOfLongestSubstring(char * s){
   int MaxLength = 0;
   memset(gHashTable, 0, sizeof(gHashTable));
   char* p = s;//工作指针指向s的开头
   char* head = s;//记录当前字串的头
   int size;//记录字符串数组的长度
   size = strlen(s);//获取数组长度

   if (s == NULL){
       return 0;
   }
   if (size == 1){
       return 1;
   }
   int cnt;
   int i = 0;
   while (*p){
        cnt = p - head;
        if (cnt > MaxLength){
            MaxLength = cnt;            
            printf("第%d遍,cnt = %d, MaxLength = %d\n", ++i, cnt, MaxLength);
        }
        if (isDuplicated(p)){//重复

           while (*p != *head){
               gHashTable[*head] = 0;
               head++;
           }
           gHashTable[*head] = 0;
           head++;;
       }
       else{//不重复
           gHashTable[*p] = *p;
           p++;
       }
   }
   int num = p - head;;
    if (num > MaxLength){
           MaxLength = num;
    }
    return MaxLength;
}