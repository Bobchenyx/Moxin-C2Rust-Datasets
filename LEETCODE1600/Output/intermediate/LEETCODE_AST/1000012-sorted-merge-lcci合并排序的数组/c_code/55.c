void q_sort(int left, int right, int v[]){
    int l = left, r = right, x = v[(left+right)/2];
    while(l <= r){
        while(v[l] < x) l++;
        while(v[r] > x) r--;
        if(l <= r){
            int tmp = v[l];
            v[l] = v[r];
            v[r] = tmp;
            l++, r--;
        }
    }
    if(l < right) q_sort(l, right, v);
    if(left < r) q_sort(left, r, v);
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    for(int i = m; i < ASize; i++){
        A[i] = B[j];
        j++;
    }
    q_sort(0, ASize-1, A);
}