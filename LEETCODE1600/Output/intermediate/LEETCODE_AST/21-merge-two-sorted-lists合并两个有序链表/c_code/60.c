//获取第一个节点
    if ( l1->val < l2->val ){
        new_node = l1;
        l1 = l1->next;
    } else{
        new_node = l2;
        l2 = l2->next;
    }
    new_head = new_node;