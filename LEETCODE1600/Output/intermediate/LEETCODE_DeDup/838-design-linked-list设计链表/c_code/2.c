MyLinkedList *L;
    int n;
    L = myLinkedListCreate();
    myLinkedListAddAtHead(L,1);
    myLinkedListAddAtTail(L,3);
    myLinkedListAddAtIndex(L,1,2);
    n = myLinkedListGet(L,1);
    printf("%d\n",n);

    myLinkedListDeleteAtIndex(L,1);
    n = myLinkedListGet(L,1);
    printf("%d\n",n);


    myLinkedListFree(L);
    return 0;