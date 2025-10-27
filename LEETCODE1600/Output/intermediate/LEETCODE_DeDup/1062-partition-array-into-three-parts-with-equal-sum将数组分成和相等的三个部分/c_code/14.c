bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize < 3)
        return 0;
    int sum = 0;
    for(int i = 0;i < ASize;sum += A[i ++]);
    if(sum % 3 != 0)
        return 0;
    int oneThird, twoThird, oneThirdSum, twoThirdSum, finalSum = sum / 3;
    for(oneThird = 1, oneThirdSum = A[0];oneThirdSum != finalSum && oneThird < ASize - 2;oneThirdSum += A[oneThird ++]);
    if(oneThirdSum != finalSum)
        return 0;
    for(twoThird = oneThird + 1, twoThirdSum = oneThirdSum + A[oneThird];twoThirdSum != finalSum * 2 && twoThird < ASize - 1;twoThirdSum += A[twoThird ++]);
    if(twoThirdSum != finalSum * 2)
        return 0;
    else
        return 1;
}