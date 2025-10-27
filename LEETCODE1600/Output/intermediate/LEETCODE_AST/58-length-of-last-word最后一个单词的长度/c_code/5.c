int lengthOfLastWord(char * s){
    int length = 0;
    int cur = 0;
    bool IsBreak = false;
    
    for (cur = strlen(s) - 1; 0 <= cur; cur--)
    {
        if (cur[s] == ' ' && IsBreak == true)
        {
            break;
        }

        if (cur[s] != ' ')
        {
            length++;
            IsBreak = true;
        }
    }

    return length;
}