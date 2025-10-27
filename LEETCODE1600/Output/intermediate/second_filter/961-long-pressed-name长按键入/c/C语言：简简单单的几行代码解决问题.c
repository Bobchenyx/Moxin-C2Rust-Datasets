bool isLongPressedName(char * name, char * type){
    int name_num = 0, type_num = 0, i = 0, j = 0;
    for (; name[i] && type[j]; ++i, ++j) {
        for (name_num = 1; name[i] == name[i+1]; ++name_num, ++i);
        for (type_num = 1; type[j] == type[j+1]; ++type_num, ++j);
        if ((name[i] != type[j]) || (type_num < name_num)) return false;
    }
    return (name[i] ? false :true);//如果type字符串结束了，但是name字符串还没结束，即name字符串长于type字符串
}