int hammingDistance(int x, int y){
    // 异或后不相同位置上变为1，其余是0，最终统计一下1的个数
    int xor = x ^ y;
    // 如果为0直接返回
    if (xor == 0) return 0;
    int count = 0;
    // 当xor>2的情况下
    while (xor/2 != 0){
        // 二进制下除以2余1，即可证明最后一位是1，否则就是0
        if (xor%2 == 1){
            // 如果余数是1，计数器加1
            count++;
        }
        // 除以2
        xor = xor / 2;
    }
    // 除到最后，xor=1时跳出循环，所以要加上最后一个1
    return count + 1;
}