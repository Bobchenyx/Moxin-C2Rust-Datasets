sprintf(str, "%d", num);
返回值ret是写入的长度；
把num数字格式化写入到str内。
注意此处，str + n是写入的起始位置，通过这个可以从某指定位置开始写，用index记录它的索引变化