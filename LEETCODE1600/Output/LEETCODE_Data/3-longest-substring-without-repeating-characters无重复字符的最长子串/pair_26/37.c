int lengthOfLongestSubstring(char * s){
    int visited[256] = { 0 };
    int n = strlen(s);
    int len = 0 , max = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n ; j++){
            if(visited[s[j]] == 0){
                visited[s[j]] = 1;
                len++;
            } else break;
        }
        max = max > len ? max : len;
        memset(visited , 0, sizeof(visited));
        len = 0;
    }
    return max;
}