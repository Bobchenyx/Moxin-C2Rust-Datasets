#define printf
static void BackspaceOneLevel(char *ret, int *id)
{
    while (*id > 0 && ret[*id] != '/') {
       (*id)--;
    }
    if (*id < 0) {
        *id = 0;
    }
    ret[*id] = '\0';
}

static bool IsValidString(char* ret, int len)
{
    bool rst = false;
    if (len <= 0) {
        return rst;
    }
    int i = 0;
    while (i < len && ret[i] == '.') {
        i++;
    }
    if (i == 0) {
        rst = true;
    } else if (i == 1) {
        if (ret[i] == '/' || ret[i] == NULL) {
            rst = false;
        } else {
            rst = true;
        }
    } else if (i == 2) {
        if (ret[i] == '/' || ret[i] == NULL) {
            rst = false;
        } else {
            rst = true;
        }
    } else {
        rst = true;
    }
    return rst;
}

static void InsertCharToRet(char *ret, int* id, char val, int count) 
{
    if (*id == 0 && val != '/') {
        ret[*id] = '/';
        (*id)++;
    }
    memset(&ret[*id], val, count);
    *id += count;
}

char * simplifyPath(char * path){
    char *ret = (char*)malloc(strlen(path) + 2);
    memset(ret, 0, strlen(path) + 1);
    int i = 0;
    while (*path != '\0') {
        if (*path == '.') {
            int count = 0;
            while (path[count] == '.') {
                count++;
            }
            
            if (count == 1) {
                if (path[count] != '/' && path[count] != NULL) {
                    InsertCharToRet(ret, &i, '.', count);
                }
            } else if (count == 2) {
                if (path[count] == '/' || path[count] == NULL) {
                    BackspaceOneLevel(ret, &i);
                } else {
                    InsertCharToRet(ret, &i, '.', count);
                }
            } else {
                InsertCharToRet(ret, &i, '.', count);
            }
            path += count;
            continue;
        } else if (*path == '/') {
            int count = 0;
            while (path[count] == '/') {
                count++;
            }
            if (isalpha(path[count]) || IsValidString(&path[count], strlen(path) - count)) {
                InsertCharToRet(ret, &i, *path, 1);
            }
            path += count;
            continue;
        } else {
            InsertCharToRet(ret, &i, *path, 1);
        }
        path++;
    }
    InsertCharToRet(ret, &i, '\0', 1);
    return ret;
}