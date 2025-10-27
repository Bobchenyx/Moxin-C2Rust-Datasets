#define MAX_STRING_LEN 2000

int odd(char *s, int *idx)
{
    int i = 0;
    int t = 0;
    int center = 0;
    int max = 0;
    int len = 0;

    len = (int)strlen(s);

    for (i = 0; i < len; i++)
    {
        for (t = 0; (0 <= i - t) && (i + t < len); t++)
        {
            if ((s[i - t] == s[i + t]) /*|| (s[i - t] == s[i + 1 + t])*/) {
                continue;
            }
            else {
                break;
            }
        }
		if (t > max) {
		    max = t;
			center = i;
		}
    }

    *idx = center;

	return max;

}

int even(char *s, int *idx)
{
    int i = 0;
    int t = 0;
    int center = 0;
    int max = 0;
    int len = 0;

    len = (int)strlen(s);

    for (i = 0; i < len; i++)
    {
        for (t = 0; (0 <= i - t) && (i + 1 + t < len); t++)
        {
            if (/*||(s[i - t] == s[i + t])  */(s[i - t] == s[i + 1 + t])) {
                continue;
            }
            else {
                break;
            }
        }
		if (t > max) {
		    max = t;
			center = i;
		}
    }

    *idx = center;

	return max;

}


char * longestPalindrome(char * s){
    int odd_center = 0;
    int odd_max = 0;
    int even_center = 0;
    int even_max = 0;    
	int center = 0;
	int max = 0;
	char *sub = NULL;

    odd_max = odd(s, &odd_center);
	even_max = even(s, &even_center);

	sub = (char *)malloc(MAX_STRING_LEN*sizeof(char));
    memset(sub, 0x0, MAX_STRING_LEN*sizeof(char));

	if (odd_max > even_max) {
		max = odd_max;
		center = odd_center;
	    memcpy(sub, s + center - ( max - 1 ),1 + 2 * (max - 1));
	}
	else {
	    max = even_max;
		center = even_center;
		memcpy(sub, s + center -  (max - 1),max -1 + max + 1);
	}

    return sub;
}