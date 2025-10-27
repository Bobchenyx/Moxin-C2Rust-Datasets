char * countAndSay(int n){
	//申请两个字符串处理数据 第一步的时候只有一个‘1’
	char* str = (char*)malloc(sizeof(char) * 10000);
	char* temp = (char*)malloc(sizeof(char) * 10000);
	str[0] = '1'; str[1] = '\0';

    //因为这个函数输出是从n=2那种情况开始的，所以要n-1
    if(n--==1)
        return str;

	//执行n个步骤
	for (int i = 0; i < n; ++i)
	{
		//根据str形成新的字符串
		int StrIter = 0, TempIter = 0;
		while (str[StrIter] != '\0')
		{
			//统计一种字符连续出现的次数
			char TheNum = str[StrIter];
			int  Times= 0;
			while (str[StrIter] == TheNum)
			{
				++Times;
				++StrIter;
			}
			//按照 “次数-字符” 存入新字符串里
			temp[TempIter++] = (char)(((int)'0') + Times);
			temp[TempIter++] = TheNum;
		}
		temp[TempIter] = '\0';
		char* sp = temp;
		temp = str;
		str = sp;
	}
	free(temp);
	return str;
}