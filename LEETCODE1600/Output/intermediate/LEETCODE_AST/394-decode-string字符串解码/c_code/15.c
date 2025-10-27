char* decode(char* s, int* pos) {
    int len = strlen(s);
    int cnt = 0;
    int curPos = *pos;
    char *result = (char*)malloc(sizeof(char));
    memset(result, 0, sizeof(char));
    while(*pos<len && s[*pos]!=']')
    {
        if(s[*pos]<'0' || s[*pos]>'9')
        {    
            if(strlen(result) > 1)
                result = (char*)realloc(result, sizeof(char)+strlen(result));
            else
                result = (char*)realloc(result, sizeof(char));
            strncat(result, &s[*pos], 1);            
            *pos = *pos + 1;
        }
        else
        {
            int cnt = 0;   
            while(*pos<len && s[*pos]>='0' && s[*pos]<='9')
            {
                cnt = cnt*10 + s[*pos] - '0';
                *pos = *pos + 1;
            }
            *pos = *pos + 1;
            char* temp = decode(s, pos);
            *pos = *pos + 1;
            if(strlen(result) < strlen(temp))
                result = (char*)realloc(result, cnt*strlen(temp)*sizeof(char)+1);
            else
                result = (char*)realloc(result, cnt*len*sizeof(char)+strlen(result)+1);
            for(int i=0; i<cnt; ++i)
            {
                strncat(result, temp, strlen(temp));
            }
            cnt = 0;
        }          
    }
    return result;
}

char* decodeString(char* s) {
    int pos = 0;
    char *result = decode(s, &pos);
    result[strlen(result)] = '\0';
    return result;
}