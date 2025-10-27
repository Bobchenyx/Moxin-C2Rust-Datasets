int swi(char ch)
{
    switch (ch)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char* s) {
    int i, sum = 0;
    for (i = 0; *(s + i + 1) != '\0'; i++);
    for (; i >= 0; i--)
    {
        if (i - 1 < 0)
            sum += swi(*(s + i));
        else if (swi(*(s + i - 1)) < swi(*(s + i)))
        {
            sum += swi(*(s + i)) - swi(*(s + i - 1));
            i--;
        }
        else
            sum += swi(*(s + i));
    }
    return sum;
}