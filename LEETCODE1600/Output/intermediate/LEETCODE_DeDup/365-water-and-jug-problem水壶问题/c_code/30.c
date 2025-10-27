// 最大公约数
int max(int a, int b)
{
    if (a == 0 || b == 0)
        return b + a;

    while(a != b){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

bool canMeasureWater(int x, int y, int z){

    if( x + y < z)
        return false;

    if(z == 0)
        return true;

    int n = max(x, y);

    if(z % n == 0)
        return true;

    return false;
}