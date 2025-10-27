#define S_ODD  1
#define S_EVEN 0
int nim(int n)
{
	int dp1, dp2, dp3;
	if (n == 0) {
		return S_EVEN; 
	}
	if (n == 1 || n == 2 || n == 3) {
		return S_ODD; 
	}
	dp1 = nim(n - 1);
	dp2 = nim(n - 2);
	dp3 = nim(n - 3);
	/* 剩下的全都是奇数步，那么只能偶数步完成 */
	if (dp1 == S_ODD && dp2 == S_ODD && dp3 == S_ODD) {
		return S_EVEN;
	}
	return S_ODD;
}
bool canWinNim(int n){
	int cnt = nim(n);
	if (cnt == S_ODD) {
		return true;
	} else {
		return false;
	}
}