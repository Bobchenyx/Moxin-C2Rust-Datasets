int get_min(int a, int b)
{
    return a < b ? a: b;
}

int get_max(int a, int b)
{
    return a > b ? a: b;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int min_x = get_max(rec1[0], rec2[0]);
    int min_y = get_max(rec1[1], rec2[1]);
    int max_x = get_min(rec1[2], rec2[2]);
    int max_y = get_min(rec1[3], rec2[3]);

    if (min_x >= max_x) {
        return false;
    }
    if (min_y >= max_y) {
        return false;
    }

    return true;
}