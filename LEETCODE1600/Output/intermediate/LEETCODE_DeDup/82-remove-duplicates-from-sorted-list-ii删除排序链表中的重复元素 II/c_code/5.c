// 1. 用于储存符合要求的值
struct ListNode realHead = {0, NULL};
struct ListNode *pre = &realHead;
// 2. 用于遍历重复值的临时指针
struct ListNode *dup;