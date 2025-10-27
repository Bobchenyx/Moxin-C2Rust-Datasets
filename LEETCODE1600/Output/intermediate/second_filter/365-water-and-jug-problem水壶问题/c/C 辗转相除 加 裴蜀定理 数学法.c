#include <stdbool.h>

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return a > b ? gcd(b, a%b) : gcd(a, b%a);
}

bool canMeasureWater(int x, int y, int z) {
	if (x + y < z) {
		return false;
	}
    if (z == 0) return true;
    if (x == 0){
        return z==y?true:false;
    }
    if (y == 0){
        return z==x?true:false;
    }
	/* ax + by = z */
	if (z % gcd(x, y) == 0) {
		return true;
	}
	else {
		return false;
	}
}