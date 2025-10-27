int compare(char **a, char **b)
{
   //按长度排序, 从长到短
    return strlen(*b) - strlen(*a);
}

qsort(words, wordsSize, sizeof(char *), compare);