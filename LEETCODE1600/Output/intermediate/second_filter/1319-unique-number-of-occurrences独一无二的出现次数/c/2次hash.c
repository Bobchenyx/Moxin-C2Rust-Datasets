bool uniqueOccurrences(int* arr, int arrSize){
    
    int hash_table[2000];
    int hash_res_table[2000];
    memset(hash_table, 0, sizeof(int)*2000);
    memset(hash_res_table, 0, sizeof(int)*2000);
    int i = 0;
    
    while(i < arrSize){
        if(arr[i] < 0)
            hash_table[(arr[i] * -1)]++;
        else
            hash_table[(arr[i] + 1000)]++;
        i++;
    }
    
    i = 0;
    while(i < 2000){
        if(hash_table[i] > 0)
            hash_res_table[hash_table[i]]++;
        if(hash_res_table[hash_table[i]] > 1)
            return false;
        i++;
    } 
    return true;
}