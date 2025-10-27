bool isLongPressedName(char * name, char * typed){
	int i = 0;
	int n = strlen(name);
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (name[i] == typed[j])
        {
			j++;
        }
		else if (i != 0 && name[i - 1] == typed[j])
		{
			while (name[i - 1] == typed[j])
			{
				j++;
			}
            i--;//当前字符未匹配到，但是for循环i会+1.在这里减回去
		}
		else
		{
			return false;
		}
	}
	return true;
}