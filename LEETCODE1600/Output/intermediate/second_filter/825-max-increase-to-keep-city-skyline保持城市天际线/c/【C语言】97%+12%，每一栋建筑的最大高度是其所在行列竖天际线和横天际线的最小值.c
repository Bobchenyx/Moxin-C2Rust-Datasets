int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int * lrmax = NULL;
    int * udmax = NULL;
    lrmax = (int *)malloc(gridSize * sizeof(int));
    memset(lrmax, 0x00 , gridSize * sizeof(int));
    udmax = (int *)malloc((*gridColSize) * sizeof(int));
    memset(udmax, 0x00 , (*gridColSize) * sizeof(int));
    int i = 0;
    int j = 0;
    int addsum = 0;
    /*get lrmax and udmax*/
    for(i = 0; i < gridSize; i++) {
        for(j = 0, lrmax[i] = grid[i][0]; j < *gridColSize; j++) {
            lrmax[i] = lrmax[i] > grid[i][j] ? lrmax[i] : grid[i][j];
        }        
    }
    for(j = 0; j < *gridColSize; j++) {
        for(i = 0, udmax[j] = grid[0][j]; i < gridSize; i++) {
            udmax[j] = udmax[j] > grid[i][j] ? udmax[j] : grid[i][j];
        }        
    }

    //printf("lrmax = {");
    //for (i = 0; i < gridSize; i++) {
    //    printf("%d,",lrmax[i]);
    //}
    //printf("}\n");
    //printf("udmax = {");
    //for (j = 0; j < *gridColSize; j++) {
    //    printf("%d,",udmax[j]);
    //}
    //printf("}\n");

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            addsum = addsum + (lrmax[i] < udmax[j] ? lrmax[i] : udmax[j]) - grid[i][j];
        }
    }
    //printf("addsum = %d\n",addsum);
    free(lrmax);
    free(udmax);
    return addsum;     


}