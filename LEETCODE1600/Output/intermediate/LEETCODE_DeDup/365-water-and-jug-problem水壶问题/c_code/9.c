/* 计算y能通过x产生多少个数 */
bool check(int x, int y, int z)
{
    int left = 0;
    if (y == z) {
		return true;
	}
	if ((x + y) == z) {
		return true;
	}
    if (y == 0) {
        return false;
    }
    while (1) {
        if (x > left) { /* left小于x，把y桶剩下的倒到x桶，然后用y桶把x桶倒满，y桶剩余产生的数*/
            left = y - (x - left) % y;
        } else { /* left大于等于x，那么直接将left倒到x，此时y桶剩余的数 */
            left = (left - x) % y;
        }
		if (left == z || left + x == z) {
			return true;
		}
        /* 一旦为0或y则进入了循环推倒，说明所有的数已经找到，可以退出 */
        if (left == 0 || left == y) {
            break;
        }
    }
    return false;
}

bool canMeasureWater(int x, int y, int z){
    if (z > (x + y) || z < 0) {
        return false;
    }
    if (z == 0) {
        return true;
    }
    return check(x, y, z) || check(y, x, z);
}