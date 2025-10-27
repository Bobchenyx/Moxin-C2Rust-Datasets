char * convertToTitle(int n){
    int lenght = 0, temp = n;
    while (temp)
    {
        lenght++;
        temp = (temp - 1) / 26;
    }

    char *result = (char*)malloc(sizeof(char)*(lenght + 1));
    result[lenght] = 0;

    while (lenght--)
    {
        result[lenght] = (n - 1) % 26 + 'A';
        n = (n - 1) / 26;
    }
    return result;
}