len = res_r - res_l + 1;
char *res = (char *)malloc(sizeof(char) * (len + 1));
strncpy(res, s + res_l, len);
res[len] = '\0';