Node *a = prehead->next; // 先把a节点地址保存起来
prehead->next = a->next; // 把prehead->next指向b
a->next = a->next->next; // 把a->next指向c
prehead->next->next = a; // prehead->next指向b