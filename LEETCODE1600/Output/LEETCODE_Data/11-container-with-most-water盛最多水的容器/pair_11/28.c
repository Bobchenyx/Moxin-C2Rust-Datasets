int  maxArea(int* height, int heightsize) {
    int* i = height; int* j = height + heightsize - 1;
    int* ti = i; int* tj = j;
    int area = 0; int ta = 0;
    while (ti != tj) {
        //先求ta  
        if (*ti > * tj) {
            ta = *tj * (tj - ti);
            if (ta > area) { // 如果判定成功 将临时边界转为正式边界 并将较小端的临时边界向内移动一位
                area = ta; j = tj; i = ti;
            }
            tj--;
        }
        else {
            ta = *ti * (tj - ti);
            if (ta > area) { // 如果判定成功 将临时边界转为正式边界 并将较小端的临时边界向内移动一位
                area = ta; j = tj; i = ti;
            }
            ti++;
        }
    }
    return area;
}