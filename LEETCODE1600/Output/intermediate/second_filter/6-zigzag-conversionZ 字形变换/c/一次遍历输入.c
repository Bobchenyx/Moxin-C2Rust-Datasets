char* convert(char* s, int numRows)
{
    char* result = NULL;
    int len = 0;
    int start = 0;
    int groupSize = 0;
    int row = 0;
    int rowIndex[numRows];
    int where = 0;
    int i;

    if (!s || !numRows) {
        goto out;
    }

    len = strlen(s);

    result = (char*)malloc(len + 1);
    if (!result) {
        goto out;
    }

    groupSize = numRows > 1 ? (numRows * 2 - 2) : 1;
    for (i = 0; i < numRows; ++i) {
        rowIndex[i] = start;
        if (!i || i == numRows - 1) {
            start += len / groupSize + ((len % groupSize) > i);
        } else {
            start += len / groupSize * 2 + ((len % groupSize) > i) + ((len % groupSize) >= numRows * 2 - i - 1);
        }
    }

    for (i = 0; i < len; ++i) {
        where = i % groupSize;
        if (where < numRows) {
            row = where;
        } else {
            row = groupSize - where;
        }
        result[rowIndex[row]++] = s[i];
    }
    result[len] = '\0';

out:
    return result;
}