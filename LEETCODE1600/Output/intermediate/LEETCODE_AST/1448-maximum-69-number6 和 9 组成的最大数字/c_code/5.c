int maximum69Number (int num){
    int num_list[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    for (; i < 11; i++){
        num_list[i] = num % 10;
        num /= 10;
    }
    int flag = 1, new_num = 0;
    for (i = 10; i >= 0; i--){
        if (flag && num_list[i] == 6){
            num_list[i] = 9;
            flag--;
        }
        new_num = 10 * new_num + num_list[i];
    }
    return new_num;
}