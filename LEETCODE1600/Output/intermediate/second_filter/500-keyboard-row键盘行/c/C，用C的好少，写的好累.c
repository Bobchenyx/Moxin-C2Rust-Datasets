*returnSize=0;
    char **res=(char**)malloc(sizeof(char*)*wordsSize);
    char *a=(char*)calloc(59,sizeof(char));
    for(int i=0;i<58;i++){
        if(i=='Q'-65||i=='W'-65||i=='E'-65||i=='R'-65||i=='T'-65||i=='Y'-65||i=='U'-65||i=='I'-65||i=='O'-65||i=='P'-65||i=='q'-65||i=='w'-65||i=='e'-65||i=='r'-65||i=='t'-65||i=='y'-65||i=='u'-65||i=='i'-65||i=='o'-65||i=='p'-65)
            a[i]=1;
        else if(i=='A'-65||i=='S'-65||i=='D'-65||i=='F'-65||i=='G'-65||i=='H'-65||i=='J'-65||i=='K'-65||i=='L'-65||i=='a'-65||i=='s'-65||i=='d'-65||i=='f'-65||i=='g'-65||i=='h'-65||i=='j'-65||i=='k'-65||i=='l'-65)
            a[i]=2;
        else
            a[i]=3;
    }
    int i,j;
    for(i=0;i<wordsSize;i++){
        for(j=1;j<strlen(words[i]);j++){
            char t=a[words[i][0]-65];
            if(t!=a[words[i][j]-65])
                break;
        }
        if(j==strlen(words[i])){
            res[*returnSize]=(char*)calloc(strlen(words[i])+1,1);
            strcpy(res[*returnSize],words[i]);
            (*returnSize)++;
        }
    }
    return res;