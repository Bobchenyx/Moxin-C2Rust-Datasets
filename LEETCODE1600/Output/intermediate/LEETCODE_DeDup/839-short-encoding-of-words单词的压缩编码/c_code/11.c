int count;
typedef struct Trie{
    bool hasvisited;
    bool haschildren;
    struct Trie* chil[26];
}Trie;
//创建字典树
Trie* createtrie()
{
    int i;
    Trie* res = (Trie*)malloc(sizeof(Trie));
    res->hasvisited = false;
    res->haschildren = false;
    for(i= 0; i < 26;i++)
        res->chil[i] = NULL;
    return res;
}
//在添加单词的同时，进行计数
bool insertword(Trie* trie, char* word)
{
    int len,flag;
    len = strlen(word);
    char f;
    flag = 0;
    for(int i=len-1;i>=0;i--)
    {
        f = word[i];
        if(trie->chil[f-'a'] == NULL)
        {
            trie->chil[f-'a'] = createtrie();
            trie->haschildren = true;
            flag = 1;
        }
        trie = trie->chil[f-'a'];
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if(words == NULL || wordsSize <= 0)
        return 0;
    Trie* trie = createtrie();
    // 对数组进行排序
    char *temp;
    int i;
    bool ans;
    for(int i=0;i<wordsSize;i++)
	{
		int max = strlen(words[i]);
        char* maxstr = words[i];
		int index=i;
 
		//找出最大的数
		for(int j=i+1;j<wordsSize;j++)
		{
			if(strlen(words[j])>max)
			{
				max=strlen(words[j]);
                maxstr = words[j];
				index=j;
			}
			
		}
		temp=words[i];
		words[i]=maxstr;
		words[index]=temp;
	}
    count = 0;
    
    for(i = 0 ; i < wordsSize;i++)
    {
        ans = insertword(trie,words[i]);
        if(ans == true)
            count += strlen(words[i])+1;
        else
            continue;
    }
    return count;
}