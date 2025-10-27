#include <stdlib.h>
char* compressString(char* S) {
	if (strlen(S) == 1)
		return S;
	int i, j, k, n;
	char* outcome = (char*)malloc(sizeof(char) * strlen(S) * 2);
	char str[25];
	k = 0;
	for (i = 0; S[i]; i++)
	{
		outcome[k++] = S[i];
		j = 1;
		while (S[i] && (S[i] == S[i + 1]))
		{
			i++;
			j++;
		}
        if(j<10)
            outcome[k++] = '0' + j;
        else
        {
            sprintf(str, " %d", j);
		    n = 1;
		    while (str[n])
		    {
			    outcome[k++] = str[n++];
		    }
        }
	}
	outcome[k++] = '\0';
	if (strlen(outcome) < strlen(S))
		return outcome;
	return S;
}