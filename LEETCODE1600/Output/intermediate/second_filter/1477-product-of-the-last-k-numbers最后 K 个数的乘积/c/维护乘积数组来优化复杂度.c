typedef struct {
    int len, zeroIndex;
    int a[30000];
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = (ProductOfNumbers *) malloc(sizeof(ProductOfNumbers));
	obj -> len = 0;
    obj -> zeroIndex = -1;
	return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    obj -> a[obj -> len] = num;
    if (num == 0) {
        obj -> zeroIndex = obj -> len; 
        obj -> a[obj -> len] = 1;   
    } else {
        obj -> a[obj -> len] = obj -> a[obj -> len - 1] * num;
    }
    (obj -> len)++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (obj -> zeroIndex > obj -> len - k - 1) {
        return 0;
    } else {
        return obj -> a[obj -> len - 1] / obj -> a[obj -> len - k - 1];
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    if (obj) {
        free(obj);
    }
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/