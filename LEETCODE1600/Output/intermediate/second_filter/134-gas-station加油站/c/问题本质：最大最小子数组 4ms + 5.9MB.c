int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int left_gas, *diff;
    int i, last_p1, last_p2, start_p, cur_gas, left_max, left_min;

    left_gas = 0;
    diff = malloc(sizeof(int) * gasSize);
    for (i = 0; i < gasSize; i++) {
        diff[i] = gas[i] - cost[i];
        left_gas += diff[i];
    }
    if (left_gas < 0) {
        return -1;
    }

    //最大子数组
    last_p1 = 0;
    start_p = 0;
    cur_gas = 0;
    left_max = 0;
    for (i = 0; i < gasSize; i++) {
        cur_gas += diff[i];
        if (cur_gas < 0) {
            start_p = i + 1;
            //printf("change start_p [%d]\n", start_p);
            cur_gas = 0;
        } else {
            if (cur_gas > left_max) {
                left_max = cur_gas;
                last_p1 = start_p;
            }
        }
    }

    //最小子数组
    last_p2 = 0;
    cur_gas = 0;
    left_min = 0;
    for (i = 0; i < gasSize; i++) {
        cur_gas += diff[i];
        if (cur_gas > 0) {
            //printf("change last_p2 [%d]\n", last_p2);
            cur_gas = 0;
        } else {
            if (cur_gas < left_min) {
                last_p2 = i + 1;
                left_min = cur_gas;
            }
        }
    }
    //printf("max %d, min %d\n", left_max, left_min);

    if (left_max + left_min >= 0) {
        return last_p1;
    } else {
        return last_p2;
    }

}