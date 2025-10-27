bool isPalindrome(int x)
{
    int tmp = x;
    long output = 0;

    if (x < 0) {
        return false;
    }

    while (tmp) {
        output = output * 10 + tmp % 10;
        tmp = tmp / 10;
    }

    if (x == output) {
        return true;
    }

    return false;
}