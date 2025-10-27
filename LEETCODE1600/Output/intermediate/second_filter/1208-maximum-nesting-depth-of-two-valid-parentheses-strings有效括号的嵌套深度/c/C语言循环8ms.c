/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxDepthAfterSplit(char *seq, int *size)
{
    if (seq == NULL || *seq == '\0')
        return NULL;
    *size = strlen(seq);
    int *result = malloc(*size * sizeof(int));
    assert(result != NULL);

    int level = 0;
    for (int i = 0; i < *size; i++)
        result[i] = 1 & ((seq[i] == '(') ? level++ : --level);

    return result;
}