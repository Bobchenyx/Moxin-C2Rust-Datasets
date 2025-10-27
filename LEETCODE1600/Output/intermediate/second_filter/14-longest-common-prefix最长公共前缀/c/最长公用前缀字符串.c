char * longestCommonPrefix(char ** strs, int strsSize){
    int cnt = 0;
	int m = 0;
	int i = 0;	//列索引
	int j = 0;	//行索引
	char *p = NULL;// = (char*)malloc(sizeof(char)*(strlen(*strs)+2));


    if(strsSize == 0)
    {
        return "";
    }
    else if(strsSize == 1)
    {
        return *strs;
    }

	for(i = 0; i < strlen(*strs); i++)	//外循环:以第一个字符串对标
	{
		for(j = 1; j < strsSize; j++)	//字符串内循环：遍历后续
		{
			/*if(*(*(strs+j)+i) == '\0')	//提前结束break
			{
				i = strlen(*strs); //强行退出外循环
				break;
			}	
			else */if(*(*(strs+j)+i) != *((*strs)+i))  //不一样break
			{
				i = strlen(*strs); //强行退出外循环
				break;
			}
			
			if(j >= (strsSize-1))
			{
				cnt ++;
			}
		}
	}

    p = (char*)malloc(sizeof(char)*(cnt+1));    //用的时候在申请空间

	for(m = 0; m < cnt; m++)
	{
		p[m] = strs[0][m];
	}
	p[m] = '\0';
	
	return p;
}