int maxSubArray(int* array, int length){
    
    bool hasPositiveValue = false;
    int tmpSstart = 0;
    int negMaxValue = array[0];
    while (tmpSstart < length) {
        if (array[tmpSstart] >0) {
            hasPositiveValue = true;
            break;
        }
        else {
            if (negMaxValue < array[tmpSstart]) {
                negMaxValue = array[tmpSstart];
            }
        }
        tmpSstart++;
    }
    
    if ( !hasPositiveValue) {
        return negMaxValue;
    }
    
    
    int start = 0;
    int right = 0;
    int tmpMaxValue = 0;
    int currentArrayValue = 0;
    while (start < length && right < length) {
        if (array[start] <0) {
            start++;
            right = start;
            continue;
        }
        if (start == right) {
            currentArrayValue = array[start];
            if (currentArrayValue > tmpMaxValue) {
                tmpMaxValue = currentArrayValue;
            }
            right++;
            while (right < length) {
                currentArrayValue = currentArrayValue + array[right];
                if (currentArrayValue > 0) {
                    right++;
                    if (currentArrayValue > tmpMaxValue) {
                        tmpMaxValue = currentArrayValue;
                    }
                }
                else {
                    start = right;
                    right = right;
                    currentArrayValue = 0;
                    break;
                }
            }
        }
    }
    
    return tmpMaxValue;
}