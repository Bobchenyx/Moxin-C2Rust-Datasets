#define MAX 200
int g_hashMap[MAX];

int Compare(const void *a, const void *b) {
    char aa = *(char *)a;
    char bb = *(char *)b;

    if (g_hashMap[(int)aa] == g_hashMap[(int)bb]) {
        return aa - bb;
    }

    return g_hashMap[(int)bb] - g_hashMap[(int)aa];
}

char * frequencySort(char * s){
    if (s == NULL) {
        return NULL;
    }

    int size = strlen(s);
    int index = 0;
    memset(g_hashMap, 0, MAX * sizeof(int));

    while(index < size) {
        g_hashMap[(int)s[index]]++;
        index++;
    }

    qsort(s, size, sizeof(char), Compare);
    return s;

}