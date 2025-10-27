int cmpf(const void *a, const void *b)
{
    return (*((char *)a)) > (*((char *)b));
}

void countalpha(char *s, int len, int *numscount)
{
    int i = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == 'a') {
            numscount[0]++;
        } else if (s[i] == 'b') {
            numscount[1]++;
        } else if (s[i] == 'c') {
            numscount[2]++;
        } else if (s[i] == 'd') {
            numscount[3]++;
        } else if (s[i] == 'e') {
            numscount[4]++;
        } else if (s[i] == 'f') {
            numscount[5]++;
        } else if (s[i] == 'g') {
            numscount[6]++;
        } else if (s[i] == 'h') {
            numscount[7]++;
        } else if (s[i] == 'i') {
            numscount[8]++;
        } else if (s[i] == 'j') {
            numscount[9]++;
        } else if (s[i] == 'k') {
            numscount[10]++;
        } else if (s[i] == 'l') {
            numscount[11]++;
        } else if (s[i] == 'm') {
            numscount[12]++;
        } else if (s[i] == 'n') {
            numscount[13]++;
        } else if (s[i] == 'o') {
            numscount[14]++;
        } else if (s[i] == 'p') {
            numscount[15]++;
        } else if (s[i] == 'q') {
            numscount[16]++;
        } else if (s[i] == 'r') {
            numscount[17]++;
        } else if (s[i] == 's') {
            numscount[18]++;
        } else if (s[i] == 't') {
            numscount[19]++;
        } else if (s[i] == 'u') {
            numscount[20]++;
        } else if (s[i] == 'v') {
            numscount[21]++;
        } else if (s[i] == 'w') {
            numscount[22]++;
        } else if (s[i] == 'x') {
            numscount[23]++;
        } else if (s[i] == 'y') {
            numscount[24]++;
        } else if (s[i] == 'z') {
            numscount[25]++;
        }
    }
    return;
}

char *originalDigits(char *s)
{
    char *alpha_tbl = "abcdefghijklmnopqrstuvwxyz";
    int numscount[26] = {0};
    int len = strlen(s);
    int i = 0;
    int j = 0;
    char *ret = NULL;

    ret = (char *)malloc(16667 * sizeof(char));
    memset(ret, 0x00, 16667 * sizeof(char));

    countalpha(s, len, numscount);
    // hanle 0 zero
    for (i = 0; i < numscount[25]; i++) {
        ret[i] = '0';
    }
    numscount[4] = numscount[4] - numscount[25];
    numscount[17] = numscount[17] - numscount[25];
    numscount[14] = numscount[14] - numscount[25];
    numscount[25] = numscount[25] - numscount[25];
    j = i;
    // hanle 2 two
    for (i = i; i < j + numscount[22]; i++) {
        ret[i] = '2';
    }
    numscount[19] = numscount[19] - numscount[22];
    numscount[14] = numscount[14] - numscount[22];
    numscount[22] = numscount[22] - numscount[22];
    j = i;

    // handle 4 four
    for (i = i; i < j + numscount['u' - 'a']; i++) {
        ret[i] = '4';
    }
    numscount['f' - 'a'] = numscount['f' - 'a'] - numscount['u' - 'a'];
    numscount['o' - 'a'] = numscount['o' - 'a'] - numscount['u' - 'a'];
    numscount['r' - 'a'] = numscount['r' - 'a'] - numscount['u' - 'a'];
    numscount['u' - 'a'] = numscount['u' - 'a'] - numscount['u' - 'a'];
    j = i;

    // handle 6 six
    for (i = i; i < j + numscount[23]; i++) {
        ret[i] = '6';
    }
    numscount[18] = numscount[18] - numscount[23];
    numscount[8] = numscount[8] - numscount[23];
    numscount[23] = numscount[23] - numscount[23];
    j = i;

    // handle 8 eight
    for (i = i; i < j + numscount[6]; i++) {
        ret[i] = '8';
    }
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['g' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['g' - 'a'];
    numscount['h' - 'a'] = numscount['h' - 'a'] - numscount['g' - 'a'];
    numscount['t' - 'a'] = numscount['t' - 'a'] - numscount['g' - 'a'];
    numscount['g' - 'a'] = numscount['g' - 'a'] - numscount['g' - 'a'];
    j = i;


    // handle 3 three
    for (i = i; i < j + numscount['r' - 'a']; i++) {
        ret[i] = '3';
    }
    numscount['t' - 'a'] = numscount['t' - 'a'] - numscount['r' - 'a'];
    numscount['h' - 'a'] = numscount['h' - 'a'] - numscount['r' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['r' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['r' - 'a'];
    numscount['r' - 'a'] = numscount['r' - 'a'] - numscount['r' - 'a'];
    j = i;

    // handle 7 seven
    for (i = i; i < j + numscount['s' - 'a']; i++) {
        ret[i] = '7';
    }
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['s' - 'a'];
    numscount['v' - 'a'] = numscount['v' - 'a'] - numscount['s' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['s' - 'a'];
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['s' - 'a'];
    numscount['s' - 'a'] = numscount['s' - 'a'] - numscount['s' - 'a'];
    j = i;

    // handle 1 one
    for (i = i; i < j + numscount['o' - 'a']; i++) {
        ret[i] = '1';
    }
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['o' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['o' - 'a'];
    numscount['o' - 'a'] = numscount['o' - 'a'] - numscount['o' - 'a'];
    j = i;

    // handle 5 five
    for (i = i; i < j + numscount['v' - 'a']; i++) {
        ret[i] = '5';
    }
    numscount['f' - 'a'] = numscount['f' - 'a'] - numscount['v' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['v' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['v' - 'a'];
    numscount['v' - 'a'] = numscount['v' - 'a'] - numscount['v' - 'a'];
    j = i;

    // handle 9 nine
    for (i = i; i < j + numscount['i' - 'a']; i++) {
        ret[i] = '9';
    }
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['i' - 'a'];
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['i' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['i' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['i' - 'a'];
    j = i;

    qsort(ret, j, sizeof(char), cmpf);
    return ret;
}